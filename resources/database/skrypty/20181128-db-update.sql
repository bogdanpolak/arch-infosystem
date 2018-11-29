
alter table op_slfun add kod_sys varchar(3) ;

UPDATE op_slfun SET kod_sys = (SUBSTRING(op_slfun.kod_funsys FROM 1 FOR (char_length(kod_funsys)-4)))

alter table op_slfun add kod_fun varchar(3);

update op_slfun
set kod_fun = Right(KOD_FUNSYS,3);


alter table op_opfun add kod_sys varchar(3);

UPDATE op_opfun SET kod_sys = (SUBSTRING(op_opfun.kod_funsys FROM 1 FOR (char_length(kod_funsys)-4)))

alter table op_opfun add kod_fun varchar(3);

update op_opfun
set kod_fun = Right(KOD_FUNSYS,3);

alter table op_opfun drop constraint OP_PK_OPFUN;
alter table op_opfun drop KOD_FUNSYS;

alter table op_slfun drop constraint OP_PK_SLFUN;
alter table op_slfun drop KOD_FUNSYS;

