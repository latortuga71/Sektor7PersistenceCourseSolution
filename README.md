# Sektor7PersistenceCourseSolution

## Solution to https://institute.sektor7.net/courses/rto-windows-persistence/311173-assignments/887088-assignment-4

## Steps
* Create telephony service provider
* Edit registry to register service provider
* Move dll to system32
* On telephony service start will execute code as network service before elevating to system and executing notepad.

### Big thanks to https://github.com/itm4n/PrintSpoofer for the elevation code and technique!


### Links
* https://securelist.com/darkpulsar/88199/
* https://docs.microsoft.com/en-us/windows/win32/tapi/microsoft-telephony-overview
* https://docs.microsoft.com/en-us/windows/win32/tapi/tspi-basic-telephony-functions?redirectedfrom=MSDN
* https://itm4n.github.io/printspoofer-abusing-impersonate-privileges/
* https://github.com/itm4n/PrintSpoofer
