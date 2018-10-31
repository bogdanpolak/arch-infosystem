SET fb_gbak_exe="C:\Program Files (x86)\Firebird\Firebird_2_5\bin\gbak.exe"
SET user=SYSDBA
SET pass="masterkey"
SET database="klienci.fdb"
SET backup_fname="klienci.firebird.bak"

%fb_gbak_exe% -RECREATE_DATABASE OVERWRITE -VERIFY -USER %user% -PASSWORD %pass% %backup_fname% %database%
@pause