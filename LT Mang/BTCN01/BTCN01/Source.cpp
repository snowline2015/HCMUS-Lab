#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <algorithm>
#include <fstream>

#pragma comment( lib, "wsock32.lib" )
#pragma comment( lib, "Ws2_32.lib")
#pragma comment( lib, "Winmm.lib")

#define PORT 80
#define DEFAULT_MSG_LENGTH 4096


struct URL {
    // "http://www.appinf.com:88/sample?example-query#frag"
    std::string protocol; // "http"
    std::string domain; // "www.appinf.com"
    std::string host; // "appinf.com"
    std::string port; // 88
    std::string path; // "/sample"
    std::string query; // "example-query"
    std::string frag; // "frag"
};


std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \n\r\t");
    size_t until = str.find_last_not_of(" \n\r\t");
    std::string::const_iterator i = start == std::string::npos ? str.begin() : str.begin() + start;
    std::string::const_iterator x = until == std::string::npos ? str.end() : str.begin() + until + 1;
    return std::string(i, x);
}


URL url_parse(const std::string& raw_url) {
    std::string path, domain, x, protocol, port, query;
    int offset = 0;
    size_t pos1, pos2, pos3, pos4;
    x = trim(raw_url);
    offset = offset == 0 && x.compare(0, 8, "https://") == 0 ? 8 : offset;
    offset = offset == 0 && x.compare(0, 7, "http://") == 0 ? 7 : offset;
    pos1 = x.find_first_of('/', offset + 1);
    path = pos1 == std::string::npos ? "" : x.substr(pos1);
    domain = std::string(x.begin() + offset, pos1 != std::string::npos ? x.begin() + pos1 : x.end());
    path = (pos2 = path.find("#")) != std::string::npos ? path.substr(0, pos2) : path;
    port = (pos3 = domain.find(":")) != std::string::npos ? domain.substr(pos3 + 1) : "";
    domain = domain.substr(0, pos3 != std::string::npos ? pos3 : domain.length());
    protocol = offset > 0 ? x.substr(0, offset - 3) : "";
    query = (pos4 = path.find("?")) != std::string::npos ? path.substr(pos4 + 1) : "";
    path = pos4 != std::string::npos ? path.substr(0, pos4) : path;
    URL uri;
    uri.protocol = protocol;
    uri.domain = domain;
    size_t pos = 0;
    if ((pos = domain.find("www.")) != std::string::npos)
        uri.host = domain.substr(pos + 4, domain.length());
    else uri.host = domain;
    uri.path = path;
    uri.port = port;
    uri.query = query;
    return  uri; 
}


void closeSocket(SOCKET socket) {
    closesocket(socket);
    socket = INVALID_SOCKET;
    WSACleanup();
}


int hexToDec(std::string hexVal) {
    std::transform(hexVal.begin(), hexVal.end(), hexVal.begin(), ::toupper);
    int len = hexVal.size();
    int base = 1;
    int dec_val = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (hexVal[i] >= '0' && hexVal[i] <= '9') {
            dec_val += (int(hexVal[i]) - 48) * base;
            base = base * 16;
        }
        else if (hexVal[i] >= 'A' && hexVal[i] <= 'F') {
            dec_val += (int(hexVal[i]) - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}


int main(int argc, char** argv) {
    argc = 3;
    argv[1] = (char*)"http://jigsaw.w3.org/HTTP/ChunkedScript";
    argv[2] = (char*)"output.txt";
    if (argc != 3) {
        
        return -1;
    }

    WSADATA wsaData;
    int wsOK = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsOK != 0) {
        std::cout << "Cannot initialize winsock. Application is now exiting..." << std::endl;
        return -1;
    }

    URL myURL = url_parse(std::string(argv[1]));

    hostent* host_info = gethostbyname(myURL.host.c_str());
    in_addr addr;

    if (host_info == NULL) {
        DWORD dw = WSAGetLastError();
        if (dw != 0) {
            if (dw == WSAHOST_NOT_FOUND) {
                std::cout << "Host is not found. Application is now exiting..." << std::endl;
                return -1;
            }
            else if (dw == WSANO_DATA) {
                std::cout << "No data record is found. Application is now exiting..." << std::endl;
                return -1;
            }
            else {
                std::cout << "Function failed with an error : " << dw << std::endl;
                return -1;
            }
        }
    }
    else {
        int i = 0;
        while (host_info->h_addr_list[i] != 0) {
            addr.s_addr = *(u_long*)host_info->h_addr_list[i++];
            //std::cout << "\nIP Address " << inet_ntoa(addr);
        }
    }

    SOCKET sockid = socket(PF_INET, SOCK_STREAM, 0);
    if (sockid == INVALID_SOCKET) {
        std::cout << "Cannot create socket. Application is now exiting..." << std::endl;
        closeSocket(sockid);
        return -1;
    }

    struct sockaddr_in server;
    // ZeroMemory(&server, sizeof(server));
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = *((unsigned long*)host_info->h_addr);

    if (inet_pton(AF_INET, inet_ntoa(addr), &server.sin_addr) <= 0) {
        std::cout << "Invalid address / Address not supported. Application is now exiting..." << std::endl;
        closeSocket(sockid);
        return -1;
    }

    if (connect(sockid, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cout << "Connection Failed. Application is now exiting..." << std::endl;
        closeSocket(sockid);
        return -1;
    }

    std::string req;
    if (myURL.path != "") {
        if (myURL.query != "")
            req = "GET " + myURL.path + "?" + myURL.query + " HTTP/1.1\r\nHost: " + myURL.host + "\r\nConnection: keep-alive\r\n\r\n";
        else
            req = "GET " + myURL.path + " HTTP/1.1\r\nHost: " + myURL.host + "\r\nConnection: keep-alive\r\n\r\n";
    }
    else {
        if (myURL.query != "")
            req = "GET /?" + myURL.query + " HTTP/1.1\r\nHost: " + myURL.host + "\r\nConnection: keep-alive\r\n\r\n";
        else
            req = "GET / HTTP/1.1\r\nHost: " + myURL.host + "\r\nConnection: keep-alive\r\n\r\n";
    }

    if (send(sockid, req.c_str(), strlen(req.c_str()), 0) != (int)req.length()) {
        std::cout << "Error in sending request. Application is now exiting..." << std::endl;
        closeSocket(sockid);
        return -1;
    }

    std::ofstream fs(argv[2]);

    char tempmsg[DEFAULT_MSG_LENGTH];
    char* content = nullptr;
    unsigned int length = 0;
    size_t received_len = 0;
    int count = 0;
    size_t current_pos = 0;
    bool firstFlag = true, contentLength = false, chunk_finish = true;
    
    while ((received_len = recv(sockid, tempmsg, DEFAULT_MSG_LENGTH - 1, 0)) > 0) {
        tempmsg[received_len] = '\0';

        std::cout << tempmsg;

        if (firstFlag) {
            if (std::string(tempmsg).find("Content-Length") == std::string::npos && std::string(tempmsg).find("Transfer-Encoding") == std::string::npos) {
                closeSocket(sockid);
                fs.close();
                return 0;
            }

            // Content_Length
            if (std::string(tempmsg).find("Content-Length") != std::string::npos) {
                contentLength = true;
                std::size_t temp = std::string(tempmsg).find("Content-Length"),
                    end_pos = std::string(tempmsg).find("\r\n", temp);
                std::string content_length = std::string(tempmsg).substr(temp, end_pos - temp);
                length = stoi(content_length.erase(0, 16));

                content = new char[length + 1];
                content[length] = '\0';
                size_t signal = std::string(tempmsg).find("\r\n\r\n");
                for (int i = signal + 4; tempmsg[i] != '\0'; i++) {
                    content[count] = tempmsg[i];
                    count++;
                }

                // Stop receiving data if receive enough data
                if (count == length)
                    break;
            }

            // Transfer-Encoding
            else {
                contentLength = false;
                size_t signal = std::string(tempmsg).find("\r\n\r\n"),
                    end_pos = std::string(tempmsg).find("\r\n", signal + 4);
                std::string content_length = std::string(tempmsg).substr(signal + 4, end_pos - (signal + 4));
                length = hexToDec(content_length);
                if (length == 0)
                    break;
                content = new char[length + 1];
                content[length] = '\0';
                for (int i = end_pos + 2; tempmsg[i] != '\0'; i++) {
                    if (count == length)
                        break;
                    content[count] = tempmsg[i];
                    current_pos = i;
                    count++;
                }

                // if not receive enough first chunk for the first time
                if (count != length) {
                    chunk_finish = false;
                    memset(tempmsg, 0, DEFAULT_MSG_LENGTH);
                    current_pos = 0;
                    firstFlag = false;
                    continue;
                }

                for (int i = 0; i < length; i++)
                    fs << content[i];
                fs << "\r\n";
                delete[] content;
                    
                // if receive only 1 chunk in the first time
                if (tempmsg[current_pos + 3] == '\0') {
                    memset(tempmsg, 0, DEFAULT_MSG_LENGTH);
                    current_pos = 0;
                    firstFlag = false;
                    continue;
                }
                
                while (true) {
                    end_pos = std::string(tempmsg).find("\r\n", current_pos + 2);
                    content_length = std::string(tempmsg).substr(current_pos + 3, end_pos - (current_pos + 3));
                    length = hexToDec(content_length);
                    if (length == 0)
                        break;

                    content = new char[length + 1];
                    content[length] = '\0';
                    count = 0;
                    for (int i = end_pos + 2; tempmsg[i] != '\0'; i++) {
                        if (count == length)
                            break;
                        content[count] = tempmsg[i];
                        current_pos = i;
                        count++;
                    }

                    for (int i = 0; i < length; i++)
                        fs << content[i];
                    fs << "\r\n";
                    delete[] content;

                    if (tempmsg[current_pos + 3] == '\0')
                        break;
                }
                if (length == 0)
                    break;
                current_pos = 0;
            }
            firstFlag = false;
        }
        else {
            if (contentLength) {
                for (int i = 0; tempmsg[i] != '\0'; i++) {
                    content[count] = tempmsg[i];
                    count++;
                }
                if (count == length)
                    break;
            }
            else {
                if (chunk_finish == false) {
                    for (int i = current_pos; tempmsg[i] != '\0'; i++) {
                        if (count == length)
                            break;
                        content[count] = tempmsg[i];
                        current_pos = i;
                        count++;
                    }
                    for (int i = 0; i < length; i++)
                        fs << content[i];
                    fs << "\r\n";
                    delete[] content;

                    if (tempmsg[current_pos + 3] == '\0') {
                        memset(tempmsg, 0, DEFAULT_MSG_LENGTH);
                        current_pos = 0;
                        continue;
                    }
                    current_pos += 3;
                    chunk_finish = true;
                }

                while (true) {
                    size_t end_pos = std::string(tempmsg).find("\r\n", current_pos);
                    std::string content_length = std::string(tempmsg).substr(current_pos, end_pos - current_pos);
                    length = hexToDec(content_length);
                    if (length == 0)
                        break;

                    content = new char[length + 1];
                    content[length] = '\0';
                    count = 0;
                    for (int i = end_pos + 2; tempmsg[i] != '\0'; i++) {
                        if (count == length)
                            break;
                        content[count] = tempmsg[i];
                        current_pos = i;
                        count++;
                    }

                    for (int i = 0; i < length; i++)
                        fs << content[i];
                    fs << "\r\n";
                    delete[] content;

                    if (tempmsg[current_pos + 3] == '\0')
                        break;
                    current_pos += 3;
                }
                if (length == 0)
                    break;
                current_pos = 0;
            }
        }
        memset(tempmsg, 0, DEFAULT_MSG_LENGTH);
    }

    if (contentLength) {
        for (int i = 0; i < length; i++) 
            fs << content[i];
        fs << "\r\n";
    }

    closeSocket(sockid);
    fs.close();

    return 1;
}