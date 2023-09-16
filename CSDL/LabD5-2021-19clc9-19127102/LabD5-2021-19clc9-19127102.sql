-- 19127102
-- Võ Hoàng Gia Bảo
-- snowline2015@gmail.com
-- Ngày làm bài: 29/06/2021

-- C5
create database DB_QLDeTai_19127102
go

use DB_QLDeTai_19127102
go

create table GIAOVIEN (
MAGV varchar(3), 
HOTEN nvarchar(100), 
LUONG float, 
PHAI nvarchar(3), 
NGSINH date, 
DIACHI nvarchar(200), 
GVQLCM varchar(3) NULL, 
MABM nvarchar(4)
primary key (MAGV)
)
go

create table GV_DT (
MAGV varchar(3), 
DIENTHOAI varchar(10)
primary key (MAGV, DIENTHOAI)
)
go

create table BOMON (
MABM nvarchar(4), 
TENBM nvarchar(100), 
PHONG char(3), 
DIENTHOAI varchar(10), 
TRUONGBM varchar(3) NULL,
MAKHOA varchar(4), 
NGAYNHANCHUC date NULL
primary key (MABM)
)
go

create table KHOA (
MAKHOA varchar(4), 
TENKHOA nvarchar(100), 
NAMTL int, 
PHONG char(3), 
DIENTHOAI varchar(10), 
TRUONGKHOA varchar(3), 
NGAYNHANCHUC date
primary key (MAKHOA)
)
go

create table DETAI (
MADT char(3), 
TENDT nvarchar(100), 
CAPQL nvarchar(10), 
KINHPHI float, 
NGAYBD date, 
NGAYKT date, 
MACD char(4), 
GVCNDT varchar(3)
primary key (MADT)
)
go

create table CHUDE (
MACD char(4), 
TENCD nvarchar(100)
primary key (MACD)
)
go

create table CONGVIEC (
MADT char(3), 
STT int, 
TENCV nvarchar(100), 
NGAYBD datetime, 
NGAYKT datetime
primary key (MADT, STT)
)
go

create table THAMGIADT (
MAGV varchar(3), 
MADT char(3), 
STT int, 
PHUCAP float, 
KETQUA nvarchar(4) NULL
primary key (MAGV, MADT, STT)
)
go

create table NGUOITHAN (
MAGV varchar(3),
TEN nvarchar(100),
NGSINH datetime,
PHAI nvarchar(3)
primary key(MAGV, TEN)
)
go

ALTER TABLE GIAOVIEN 
ADD CONSTRAINT FK_GIAOVIEN_GIAOVIEN FOREIGN KEY (GVQLCM) REFERENCES GIAOVIEN(MAGV),
CONSTRAINT FK_GIAOVIEN_BOMON FOREIGN KEY (MABM) REFERENCES BOMON(MABM),
CONSTRAINT CK_GIAOVIEN_NGSINH CHECK (NGSINH < GETDATE()),
CONSTRAINT CK_GIAOVIEN_PHAI CHECK (PHAI IN ('Nam', N'Nữ'))
GO

ALTER TABLE KHOA 
ADD CONSTRAINT FK_KHOA_GIAOVIEN FOREIGN KEY (TRUONGKHOA) REFERENCES GIAOVIEN(MAGV), 
CONSTRAINT CK_KHOA_NAMTL CHECK (NAMTL <= DATEPART(YEAR, GETDATE())),
CONSTRAINT CK_KHOA_NGAYNHANCHUC CHECK (NGAYNHANCHUC <= GETDATE())
GO

ALTER TABLE BOMON 
ADD CONSTRAINT FK_BOMON_KHOA FOREIGN KEY (MAKHOA) REFERENCES KHOA(MAKHOA),
CONSTRAINT FK_BOMON_GIAOVIEN FOREIGN KEY (TRUONGBM) REFERENCES GIAOVIEN(MAGV),
CONSTRAINT CK_BOMON_NGAYNHANCHUC CHECK (NGAYNHANCHUC <= GETDATE())
GO

ALTER TABLE GV_DT 
ADD CONSTRAINT FK_GV_DT_GIAOVIEN FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV)
GO

ALTER TABLE NGUOITHAN 
ADD CONSTRAINT FK_NGUOITHAN_GIAOVIEN FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV), 
CONSTRAINT CK_NGUOITHAN_PHAI CHECK (PHAI IN ('Nam', N'Nữ')),
CONSTRAINT CK_NGUOITHAN_NGSINH CHECK (NGSINH <= GETDATE())
GO

ALTER TABLE THAMGIADT 
ADD CONSTRAINT FK_THAMGIADT_GIAOVIEN FOREIGN KEY (MAGV) REFERENCES GIAOVIEN(MAGV),
CONSTRAINT FK_THAMGIADT_CONGVIEC FOREIGN KEY (MADT, STT) REFERENCES CONGVIEC(MADT, STT)
GO

ALTER TABLE CONGVIEC 
ADD CONSTRAINT FK_CONGVIEC_DETAI FOREIGN KEY (MADT) REFERENCES DETAI(MADT),
CONSTRAINT CK_CONGVIEC_NGAY CHECK (NGAYBD <= GETDATE() AND NGAYKT <= GETDATE() AND NGAYBD <= NGAYKT)
GO

ALTER TABLE DETAI 
ADD CONSTRAINT FK_DETAI_CHUDE FOREIGN KEY (MACD) REFERENCES CHUDE(MACD),
CONSTRAINT CK_DETAI_NGAY CHECK (NGAYBD <= NGAYKT AND NGAYKT <= GETDATE())
GO

INSERT INTO GIAOVIEN
VALUES ('001', N'Nguyễn Hoài An', 2000.0, 'Nam', '1973-02-15', N'25/3 Lạc Long Quân, Q.10, TP HCM', null, null),
('002', N'Trần Trà Hương', 2500.0, N'Nữ', '1960-06-20', N'125 Trần Hưng Đạo, Q.1, TP HCM', null, null),
('003', N'Nguyễn Ngọc Ánh', 2200.0, N'Nữ', '1975-05-11', N'12/21 Võ Văn Ngân Thủ Đức, TP HCM', null, null),
('004', N'Trương Nam Sơn', 2300.0, 'Nam', '1959-06-20', N'215 Lý Thường Kiệt, TP Biên Hòa', null, null),
('005', N'Lý Hoàng Hà', 2500.0, 'Nam', '1954-10-23', N'22/5 Nguyễn Xí, Q.Bình Thạnh, TP HCM', null, null),
('006', N'Trần Bạch Tuyết', 1500.0, N'Nữ', '1980-05-20', N'127 Hùng Vương, TP Mỹ Tho', null, null),
('007', N'Nguyễn An Trung', 2100.0, 'Nam', '1976-06-15', N'234 3/2, TP Biên Hòa', null, null),
('008', N'Trần Trung Hiếu', 1800.0, 'Nam', '1977-08-06', N'22/11 Lý Thường Kiệt, TP Mỹ Tho', null, null),
('009', N'Trần Hoài Nam', 2000.0, 'Nam', '1975-11-22', N'234 Trần Não, An Phú, TP HCM', null, null),
('010', N'Phạm Nam Thanh', 1500.0, 'Nam', '1980-12-12', N'221 Hùng Vương, Q.5, TP HCM', null, null)
go

insert into CHUDE
values ('NCPT', N'Nghiên cứu phát triển'),
('QLGD', N'Quản lý giáo dục'),
(N'ƯDCN', N'Ứng dụng công nghiệp')
go

insert into DETAI
values ('001', N'HTTT quản lý các trường ĐH', N'ĐHQG', 20.0, '2007-10-20', '2008-10-20', 'QLGD', '002'),
('002', N'HTTT quản lý giáo vụ cho một Khoa', N'Trường', 20.0, '2000-10-12', '2001-10-12', 'QLGD', '002'),
('003', N'Nghiên cứu chế tạo sợi Nanô Platin', N'ĐHQG', 300.0, '2008-05-15', '2010-05-15', 'NCPT', '005'),
('004', N'Tạo vật liệu sinh học bằng màng ối người', N'Nhà nước', 100.0, '2007-01-01', '2009-12-31', 'NCPT', '004'),
('005', N'Ứng dụng hóa học xanh', N'Trường', 200.0, '2003-10-10', '2004-12-10', 'ƯDCN', '007'),
('006', N'Nghiên cứu tế bào gốc', N'Nhà nước', 4000.0, '2006-10-20', '2009-10-20', 'NCPT', '004'),
('007', N'HTTT quản lý thư viện ở các trường ĐH', N'Trường', 20.0, '2009-05-10', '2010-05-10', 'QLGD', '001')
go

insert into CONGVIEC
values ('001', 1, N'Khởi tạo và Lập kế hoạch', '2007-10-20', '2008-12-20'),
('001', 2, N'Xác định yêu cầu', '2008-12-21', '2009-03-21'),
('001', 3, N'Phân tích hệ thống', '2008-03-22', '2008-05-22'),
('001', 4, N'Thiết kế hệ thống', '2008-05-23', '2008-06-23'),
('001', 5, N'Cài đặt thử nghiệm', '2008-06-24', '2008-10-20'),
('002', 1, N'Khởi tạo và Lập kế hoạch', '2009-05-10', '2009-07-10'),
('002', 2, N'Xác định yêu cầu', '2009-07-11', '2009-10-11'),
('002', 3, N'Phân tích hệ thống', '2009-10-12', '2009-12-20'),
('002', 4, N'Thiết kế hệ thống', '2009-12-21', '2010-03-22'),
('002', 5, N'Cài đặt thử nghiệm', '2010-03-23', '2010-05-10'),
('006', 1, N'Lấy mẫu', '2006-10-20', '2007-02-20'),
('006', 2, N'Nuôi cấy', '2007-02-21', '2008-08-21')
go

insert into THAMGIADT
values ('001', '002', 1, 0.0, null),
('001', '002', 2, 2.0, null),
('002', '001', 4, 2.0, N'Đạt'),
('003', '001', 1, 1.0, N'Đạt'),
('003', '001', 2, 0.0, N'Đạt'),
('003', '001', 4, 1.0, N'Đạt'),
('003', '002', 2, 0.0, null),
('004', '006', 1, 0.0, N'Đạt'),
('004', '006', 2, 1.0, N'Đạt'),
('006', '006', 2, 1.5, N'Đạt'),
('009', '002', 3, 0.5, null),
('009', '002', 4, 1.5, null)
go

insert into KHOA
values ('CNTT', N'Công nghệ thông tin', 1995, 'B11', '0838123456', '002', '2005-02-20'),
('HH', N'Hóa học', 1980, 'B41', '0838456456', '007', '2001-10-15'),
('SH', N'Sinh học', 1980, 'B31', '0838454545', '004', '2000-10-11'),
('VL', N'Vật lý', 1976, 'B21', '0838223223', '005', '2003-09-18')
go

insert into NGUOITHAN
values ('001', N'Hùng', '1990-01-14', 'Nam'),
('001', N'Thủy', '1994-12-08', N'Nữ'),
('003', N'Hà', '1998-09-03', N'Nữ'),
('003', N'Thu', '1998-01-14', N'Nữ'),
('007', N'Mai', '2003-01-14', N'Nữ'),
('007', N'Vy', '2000-01-14', N'Nữ'),
('008', N'Nam', '1991-01-14', 'Nam'),
('009', N'An', '1996-01-14', 'Nam'),
('010', N'Nguyệt', '2006-01-14', N'Nữ')
go

insert into BOMON
values ('CNTT', N'Công nghệ tri thức', 'B15', '0838126126', null, 'CNTT', null),
('HHC', N'Hóa hữu cơ', 'B44', '838222222', null, 'HH', null),
('HL', N'Hóa lý', 'B42', '0838878787', null, 'HH', null),
('HPT', N'Hóa phân tích', 'B43', '0838777777', '007', 'HH', '2007-10-15'),
('HTTT', N'Hệ thống thông tin', 'B13', '0838125125', '002', 'CNTT', '2004-09-20'),
('MMT', N'Mạng máy tính', 'B16', '0838676767', '001', 'CNTT', '2005-05-15'),
('SH', N'Sinh hóa', 'B33', '0838898989', null, 'SH', null),
(N'VLĐT', N'Vật lý điện tử', 'B23', '0838234234', null, 'VL', null),
(N'VLƯD', N'Vật lý ứng dụng', 'B24', '0838454545', '005', 'VL', '2006-02-18'),
('VS', N'Vi sinh', 'B32', '0838909090', '004', 'SH', '2007-01-01')
go

UPDATE GIAOVIEN
set GVQLCM = '001' where MAGV = '009'

UPDATE GIAOVIEN
set GVQLCM = '002' where MAGV = '003'

UPDATE GIAOVIEN
set GVQLCM = '004' where MAGV = '006'

UPDATE GIAOVIEN
set GVQLCM = '007' where MAGV in ('008', '010')

UPDATE GIAOVIEN
set MABM = 'MMT' where MAGV in ('001', '009')

UPDATE GIAOVIEN
set MABM = 'HTTT' where MAGV in ('002', '003')

UPDATE GIAOVIEN
set MABM = 'VS' where MAGV in ('004', '006')

UPDATE GIAOVIEN
set MABM = N'VLĐT' where MAGV = '005'

UPDATE GIAOVIEN
set MABM = 'HPT' where MAGV in ('007', '008', '010')


-- D5
-- 1. Cho biết họ tên và mức lương của các giáo viên nữ. Sắp xếp tăng dần theo ngày sinh
SELECT HOTEN, LUONG
FROM GIAOVIEN
WHERE PHAI = N'Nữ'
ORDER BY NGSINH ASC
GO

-- 2. Cho biết họ tên của các giáo viên và lương của họ sau khi tăng 10%
SELECT HOTEN, LUONG*1.1
FROM GIAOVIEN
GO

-- 3. Cho biết MAGV, họ tên bắt đầy là "Nguyễn" và lương trên $2000 hoặc giáo viên là trưởng bộ môn nhận chức sau năm 1995.
-- Sắp xếp giảm dần theo lương, sau đó sắp xếp tăng dần theo MABM
SELECT GV.MAGV, GV.HOTEN, GV.LUONG, GV.MABM
FROM GIAOVIEN GV, BOMON BM
WHERE GV.HOTEN LIKE N'Nguyễn%' AND GV.LUONG > 2000
UNION
SELECT GV.MAGV, GV.HOTEN, GV.LUONG, GV.MABM
FROM GIAOVIEN GV, BOMON BM
WHERE GV.MAGV = BM.TRUONGBM AND DATEPART(YEAR, BM.NGAYNHANCHUC) > '1995'
ORDER BY GV.LUONG DESC, GV.MABM ASC
GO

-- 4. Cho biết tên những GV thuộc bộ môn có mã 'HTTT'
SELECT HOTEN
FROM GIAOVIEN 
WHERE MABM = 'HTTT'
GO

-- 5. Cho biết MAGV làm trưởng bộ môn có thân nhân
SELECT GV.MAGV
FROM GIAOVIEN GV, BOMON BM
WHERE GV.MAGV = BM.TRUONGBM AND GV.MAGV IN (SELECT MAGV FROM NGUOITHAN)
GO

-- 6. Cho biết MADT nào chưa có GV tham gia
SELECT DT.MADT
FROM DETAI DT
WHERE DT.MADT NOT IN (SELECT MADT FROM THAMGIADT)
GO

-- 7. Cho biết MAGV có than gia đề tài nhưng không có người thân
SELECT GV.MAGV
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT MAGV FROM THAMGIADT) AND GV.MAGV NOT IN (SELECT MAGV FROM NGUOITHAN)
GO

-- 8. Cho biết MAGV vừa là trưởng bộ môn, vừa là trưởng khoa
SELECT GV.MAGV
FROM GIAOVIEN GV
WHERE GV.MAGV IN (SELECT TRUONGBM FROM BOMON) AND GV.MAGV IN (SELECT TRUONGKHOA FROM KHOA)
GO