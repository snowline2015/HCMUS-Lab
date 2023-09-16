create database DB_19127102_VoHoangGiaBao_r04
go

use DB_19127102_VoHoangGiaBao_r04
go

create table MonHoc (
MaMH char(5),
TenMH nvarchar(100),
SoTCHP int,
SoTCTH int,
DonGiaHP float,
MHTienQuyet char(5)
primary key (MaMH, TenMH)
)
go

create table MonHocMo (
MaMonHoc char(5),
HocKy int,
NamHoc int,
NgayBD date, 
NgayKetThuc date,
GVLTChinh char(20), 
SoSV int
primary key (MaMonHoc)
)
go

create table GV_DayMH (
MaGV char(20),
MaMH char(5),
HocKy int,
NamHoc int,
VaiTro char(4)
primary key (MaGV)
)
go

create table GiangVien (
MaGV char(20),
HoTen nvarchar(100),
HocVi char(3)
primary key (MaGV)
)
go

alter table MonHoc 
add constraint CK_MONHOC_SOTINCHIHP check (SoTCHP in (1,2,3,4))
go

alter table MonHocMo
add constraint FK_MONHOCMO_MAMONHOC foreign key (MaMonHoc) references MonHoc(MaMH),
constraint FK_MONHOCMO_GIANGVIEN foreign key (GVLTChinh) references GiangVien(MaGV),
constraint CK_MONHOCMO_HOCKY check (HocKy in (1,2,3))
go


alter table GiangVien
add constraint CK_GIANGVIEN_HOCVI check (HocVi in ('ThS', 'TS', 'CN'))
go

alter table GV_DayMH
add constraint FK_GV_DAYMH_MONHOC foreign key (MaMH) references MonHoc(MaMH),
constraint FK_GV_DAYMH_GIANGVIEN foreign key (MaGV) references GiangVien(MaGV),
constraint CK_GV_DAYMH_VAITRO check (VaiTro in ('GVLT', 'TroGiang', 'ThucHanh'))
go

-- 5


-- 6
select GV.MaGV
from GiangVien GV
where GV.MaGV not in (select GVDMH.MaGV from  GV_DayMH GVDMH)

-- 7