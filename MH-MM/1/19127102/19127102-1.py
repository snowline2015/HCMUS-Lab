
from copy import deepcopy

# from https://en.wikipedia.org/wiki/Letter_frequency
char_freq = ['e','t','a','o','i','n','s','h','r','d','l','c','u',
             'm','w','f','g','y','p','b','v','k','j','x','q','z']
copy_char_freq = deepcopy(char_freq)

txt = input('Input cipher text: ')
# Test case: NWVKIF UWVYC TWY AFYXAKIL CD QKIWCI UNVCCIKYEP HP EIK QEANLEDDL CDP IWKCE XDFP XDYIP. UNVCCIKYEP'Y AFACAWN LIYAMF, XVHNAYEIL DFNAFI HP UWVYC, KIUIKY CD EIK WY 'XDYIP' WY TINN. EIK QVCAI OWKG, CEKII XAFG WFL QPWF HVCCIKUNAIY, AY YAOANWK CD CEWC DU CEI XDFP YGP YGAOOIK.
# Expected output: lauren faust was inspired to create fluttershy by her childhood toy earth pony posey. fluttershy's initial design, published online by faust, refers to her as 'posey' as well. her cutie mark, three pink and cyan butterflies, is similar to that of the pony sky skimmer.


def count_char_freq(str):
    freq_count = {}
    for i in str:
        if i in freq_count:
            freq_count[i] += 1
        elif i.isalpha():
            freq_count[i] = 1
    return freq_count


txt_freq = [x for x in count_char_freq(txt).items()]
sorted_txt_freq_desc = sorted(txt_freq, key=lambda x: x[1], reverse=True)

print(sorted_txt_freq_desc)
print(char_freq)


def text_replace(text, char_replaced, char_replace):
    for i in sorted_txt_freq_desc:
        if i[0] == char_replaced:
            sorted_txt_freq_desc.remove(i)
    if char_replace in copy_char_freq:
        copy_char_freq.remove(char_replace)
    return text.replace(str(char_replaced), str(char_replace))


def user_choice():
    temp = txt
    iter = 0
    removed_backup = []
    while len(sorted_txt_freq_desc) != 0:
        print('\n', sorted_txt_freq_desc, '\n', copy_char_freq, '\n', temp, '\n')

        while True:
            choice = input(
                'Input a character from the sequence to replace \'' + str(sorted_txt_freq_desc[iter][0]) + '\' : ')
            if choice in copy_char_freq and len(choice) == 1:
                removed_backup.append(
                    [sorted_txt_freq_desc[iter][0], sorted_txt_freq_desc[iter][1], choice])
                temp = text_replace(temp, sorted_txt_freq_desc[iter][0],
                                    copy_char_freq[copy_char_freq.index(str(choice))])
                print(temp)
                break
            else:
                print('The character you inputted is not available in the sequence. Please re-enter another character.')

        while True:
            if len(removed_backup) == 0:
                break
            choice = input('Do you want to continue ? (Y/N) ')
            if choice != 'Y' and choice != 'y':
                temp = temp.replace(str(removed_backup[len(removed_backup) - 1][2]),
                                    str(removed_backup[len(removed_backup) - 1][0]))
                sorted_txt_freq_desc.insert(0, (str(removed_backup[len(removed_backup) - 1][0]),
                                                removed_backup[len(removed_backup) - 1][1]))
                copy_char_freq.append(str(removed_backup[len(removed_backup) - 1][2]))
                copy_char_freq.sort(key=lambda i: char_freq.index(i))
                removed_backup.pop(len(removed_backup) - 1)
                print('Roll back:', temp)
            else:
                break
    return temp


print('\nFinal:', user_choice())







