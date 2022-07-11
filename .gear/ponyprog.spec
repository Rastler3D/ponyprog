%define origname ponyprog

Name: ponyprog
Version: 3.1.3
Release: alt1
Summary: Serial device programmer
# https://github.com/lancos/ponyprog
Source: %origname-%version.tar.gz
License: GPLv2
Group: Development/Other
Url: http://www.lancos.com/prog.html

BuildRequires: cmake libftdipp1-devel qt5-multimedia-devel
BuildRequires(pre): rpm-macros-cmake

%description
PonyProg is a serial device programmer software with a user friendly GUI
framework available for Windows and Linux. It's purpose is reading and writing
every serial device. With PonyProg and SI-Prog you can program Wafercard for
SAT, eeprom within GSM, TV or CAR-RADIO. Furthermore it can be used as a low
cost starter kit for PIC and AVR.

Ponyprog supports AVR, SPI eeprom, AVR micro, 12C bus 8bit eeprom, PIC 16 micro,
PIC 12 micro, AT89S micro and SDE2506 eeprom family chips.

%prep
%setup -n %origname-%version

%build
%cmake
%cmake_build

%install
%cmake_install

%files
%doc README.md LICENSE
/usr/bin/%origname
/usr/share/icons/%origname.png
/usr/share/%origname
/usr/share/doc/%origname
/lib/udev/rules.d/90-%origname.rules
/usr/share/applications/%origname.desktop

%changelog
* Sat Jul 9 2022 Aleksandr Khvalov <aleksandr.hvalov@mail.ru> 3.1.3-alt1
- Initial new ponyprog version based on Qt.
