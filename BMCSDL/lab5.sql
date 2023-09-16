/*----------------------------------------------------------
MASV: 19127102
HO TEN:	Vo Hoang Gia Bao
LAB: 05
NGAY: 10/5/2022
----------------------------------------------------------*/
-- CAC CAU LENH DE THUC HIEN MA HOA
USE master
GO

CREATE MASTER KEY ENCRYPTION BY PASSWORD = '19127102'
GO

CREATE CERTIFICATE MyCert WITH SUBJECT = 'MyCert'
GO


USE QLBongDa
GO

CREATE DATABASE ENCRYPTION KEY
WITH ALGORITHM = AES_256
ENCRYPTION BY SERVER CERTIFICATE MyCert
GO

ALTER DATABASE QLBongDa
SET ENCRYPTION ON
GO



/*----------------------------------------------------------
MASV: 19127102
HO TEN:	Vo Hoang Gia Bao
LAB: 05
NGAY: 12/5/2022
----------------------------------------------------------*/
-- CAC CAU LENH DE BACKUP/RESTORE CERTIFICATE
USE master
GO
BACKUP CERTIFICATE MyCert TO FILE = 'C:\VOHOANGGIABAO\MyCert'
WITH PRIVATE KEY (FILE = 'C:\VOHOANGGIABAO\MyPriKey', ENCRYPTION BY PASSWORD = '19127102')


USE master
GO
CREATE CERTIFICATE MyCert FROM FILE = 'C:\VOHOANGGIABAO\MyCert'
WITH PRIVATE KEY (FILE = 'C:\VOHOANGGIABAO\MyPriKey', DECRYPTION BY PASSWORD = '19127102')