/*----------------------------------------------------------
MASV: 19127102
HO TEN: Vo Hoang Gia Bao
MASV: 19127406
HO TEN: Ngo Huy Hoang
MASV: 19127457
HO TEN: Nguyen Tuan Kiet
LAB: 03 - NHOM
NGAY: 10/4/2022
----------------------------------------------------------*/
-- CAU LENH TAO DB
CREATE DATABASE QLSVNhom
GO
USE QLSVNhom
GO



/*----------------------------------------------------------
MASV: 19127102
HO TEN: Vo Hoang Gia Bao
MASV: 19127406
HO TEN: Ngo Huy Hoang
MASV: 19127457
HO TEN: Nguyen Tuan Kiet
LAB: 03 - NHOM
NGAY: 10/4/2022
----------------------------------------------------------*/
-- CAC CAU LENH TAO TABLE
CREATE TABLE SINHVIEN (
MASV NVARCHAR(20) PRIMARY KEY,
HOTEN NVARCHAR(100) NOT NULL,
NGAYSINH DATETIME,
DIACHI NVARCHAR(200),
MALOP VARCHAR(20),
TENDN NVARCHAR(100) NOT NULL,
MATKHAU VARBINARY(MAX) NOT NULL
)
GO

CREATE TABLE NHANVIEN (
MANV VARCHAR(20) PRIMARY KEY,
HOTEN NVARCHAR(100) NOT NULL,
EMAIL VARCHAR(20),
LUONG VARBINARY(MAX),
TENDN NVARCHAR(100) NOT NULL,
MATKHAU VARBINARY(MAX) NOT NULL,
PUBKEY VARCHAR(20)
)
GO

CREATE TABLE LOP (
MALOP VARCHAR(20) PRIMARY KEY,
TENLOP NVARCHAR(100) NOT NULL,
MANV VARCHAR(20) 
)
GO

CREATE TABLE HOCPHAN (
MAHP VARCHAR(20) PRIMARY KEY,
TENHP NVARCHAR(100) NOT NULL,
SOTC INT
)
GO

CREATE TABLE BANGDIEM (
MASV NVARCHAR(20),
MAHP VARCHAR(20),
DIEMTHI VARBINARY(MAX),
PRIMARY KEY (MASV, MAHP)
)
GO

ALTER TABLE BANGDIEM ADD CONSTRAINT FK_BANGDIEM_HOCPHAN FOREIGN KEY(MAHP)
REFERENCES HOCPHAN (MAHP)
GO

ALTER TABLE BANGDIEM ADD CONSTRAINT FK_BANGDIEM_SINHVIEN FOREIGN KEY(MASV)
REFERENCES SINHVIEN (MASV)
GO

ALTER TABLE LOP ADD CONSTRAINT FK_LOP_NHANVIEN FOREIGN KEY(MANV)
REFERENCES NHANVIEN (MANV)
GO

ALTER TABLE SINHVIEN ADD CONSTRAINT FK_SINHVIEN_LOP FOREIGN KEY(MALOP)
REFERENCES LOP (MALOP)
GO



/*----------------------------------------------------------
MASV: 19127102
HO TEN: Vo Hoang Gia Bao
MASV: 19127406
HO TEN: Ngo Huy Hoang
MASV: 19127457
HO TEN: Nguyen Tuan Kiet
LAB: 03 - NHOM
NGAY: 10/4/2022
----------------------------------------------------------*/
-- CAU LENH TAO STORED PROCEDURE
--IF NOT EXISTS (
--SELECT * FROM sys.symmetric_keys WHERE symmetric_key_id = 101
--)
--CREATE MASTER KEY ENCRYPTION BY PASSWORD = '19127102_19127406_19127457'
--GO

--IF NOT EXISTS (
--SELECT * FROM sys.certificates WHERE name = 'MyCert'
--)
--CREATE CERTIFICATE MyCert WITH SUBJECT = 'MyCert'
--GO

--OPEN SYMMETRIC KEY Key1
--DECRYPTION BY CERTIFICATE MyCert
--GO

CREATE PROC SP_INS_PUBLIC_NHANVIEN (
@MANV VARCHAR(20),
@HOTEN NVARCHAR(100),
@EMAIL VARCHAR(20),
@LUONG INT,
@TENDN NVARCHAR(100),
@MATKHAU VARCHAR(MAX)
)
AS
IF NOT EXISTS (SELECT * FROM sys.asymmetric_keys WHERE name = @MANV)
DECLARE @C NVARCHAR(MAX) = 
    'CREATE ASYMMETRIC KEY ' + @MANV + ' 
	WITH ALGORITHM = RSA_512 
	ENCRYPTION BY PASSWORD = ''' + @MATKHAU + ''''
EXEC(@C)
INSERT INTO NHANVIEN
VALUES (@MANV, @HOTEN, @EMAIL, ENCRYPTBYASYMKEY(ASYMKEY_ID(@MANV), CONVERT(VARCHAR(MAX), @LUONG)), @TENDN, HASHBYTES('SHA1', @MATKHAU), @MANV)
GO


CREATE PROC SP_SEL_PUBLIC_NHANVIEN (
@TENDN NVARCHAR(100),
@MATKHAU VARCHAR(MAX)
)
AS
SELECT MANV, HOTEN, EMAIL, CONVERT(VARCHAR(MAX), DECRYPTBYASYMKEY(ASYMKEY_ID(MANV), LUONG, CONVERT(NVARCHAR(MAX), @MATKHAU))) AS LUONGCB FROM NHANVIEN
WHERE TENDN = @TENDN AND convert(varchar(max), MATKHAU, 2) = convert(varchar(max), HASHBYTES('SHA1', @MATKHAU), 2)
GO



-- EXEC SP_INS_PUBLIC_NHANVIEN 'NV01', 'NGUYEN VAN A', 'NVA@', 3000000, 'NVA', 'abcd12'

-- EXEC SP_SEL_PUBLIC_NHANVIEN 'NVA', 'abcd12'



/*----------------------------------------------------------
MASV: 19127102
HO TEN: Vo Hoang Gia Bao
MASV: 19127406
HO TEN: Ngo Huy Hoang
MASV: 19127457
HO TEN: Nguyen Tuan Kiet
LAB: 03 - NHOM
NGAY: 15/4/2022
----------------------------------------------------------*/
EXEC SP_INS_PUBLIC_NHANVIEN 'NV01', 'NGUYEN VAN A', 'nva@yahoo.com', 3000000, 'NVA', '123456'

EXEC SP_INS_PUBLIC_NHANVIEN 'NV02', 'NGUYEN VAN B', 'nvb@yahoo.com', 2000000, 'NVB', '1234567'


-- Test Data
--INSERT LOP
--INSERT INTO LOP VALUES('L1', 'LOP1', 'NV01')
--INSERT INTO LOP VALUES('L2', 'LOP2', 'NV02')
--INSERT INTO LOP VALUES('L3', 'LOP3', 'NV01')

--INSERT SINH VIEN
--insert into SINHVIEN values('SV01', 'NGUYEN VAN A', '1/1/2001', '227 NGUYEN VAN CU', 'L1', 'SVA', HASHBYTES('MD5','123456'))
--insert into SINHVIEN values('SV02', 'NGUYEN VAN B', '2/1/2001', '227 NGUYEN VAN CU', 'L1', 'SVB', HASHBYTES('MD5','123456'))
--insert into SINHVIEN values('SV03', 'NGUYEN THI C', '3/1/2001', '227 NGUYEN VAN CU', 'L2', 'SVC', HASHBYTES('MD5','abc123'))
--insert into SINHVIEN values('SV04', 'TRAN VAN D', '4/1/2001', '227 NGUYEN VAN CU', 'L2', 'SVD', HASHBYTES('MD5','abc123'))
--INSERT INTO SINHVIEN VALUES('SV05', 'NGUYEN THI E', '1/1/2001', '227 NGUYEN VAN CU', 'L3', 'SVE', HASHBYTES('MD5','123456'))

--INSERT HOC PHAN
--INSERT INTO HOCPHAN VALUES('HP1', 'HOC PHAN 1', 4)
--INSERT INTO HOCPHAN VALUES('HP2', 'HOC PHAN 2', 4)
