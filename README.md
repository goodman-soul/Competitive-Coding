# Setting an env. for sublime text
[Check this file](https://medium.com/sophozaar/setting-an-environment-for-competitive-programming-for-c-on-ubuntu-a644083cb06d)
1. Operating System: Manjaro OS
2. Install C++ compiler : g++
  ~~~bash
  sudo pacman install g++
  ~~~
  to check the version of g++ version
 ~~~bash
 g++ version
 ~~~
3. Install Sublime Text
  for Manjaro sublime-text cannot be installed directly. You need to install snap.
  to install snap
  ~~~bash
  sudo pacman -S snapd
  ~~~
  once installed execute
  ~~~bash
  sudo systemctl enable --now snapd.socket
  ~~~
  [more info on snap for manjaro](https://snapcraft.io/docs/installing-snap-on-manjaro-linux)
  Finally, Install sublime using snap
  ~~~bash
  sudo snap install sublime-text -classic
  ~~~
  to open sublime-text from terminal type
  ~~~bash
  subl
  ~~~
  4. Setting the build system for c++
  open ***sublime > Tools > Build System > New Build System***
  paste the following
  ~~~shell script
  {
"cmd": ["g++", "-std=c++14", "$file", "-o", "${file_path}/${file_base_name}"],
"file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
"working_dir": "${file_path}",
"selector": "source.c, source.c++, source.cxx, source.cpp",
"variants":
[
{
	"name": "Run",
	"cmd": ["bash", "-c", "g++ -std=c++14 '${file}' -o '${file_path}/${file_base_name}' && xfce4-terminal -x bash -c '\"${file_path}/${file_base_name}\" ; read'"]
}
]
}
  ~~~
  save the file using ***compile***
  filename will be: **compile.sublime-built**
  & to get the location of file type in terminal
  ~~~bash
  /home/abhinaba/.config/sublime-text-3/Packages/User
  ~~~
  set built system to compile opening sublime & to use it press 
  ~~~bash 
  ctrl + b 
  ~~~
5. Precompile "bits/stdc++.h"
You should precompile the file for speed. Otherwise it take lot of time to compile the header file
###### locate bits/stdc++.h file
~~~bash
cd /usr/include/c++/<some version>/x86_64-pc-linux-gnu/bits
~~~
there you will get stdc++.h header file
compile using g++ (put the same version as build system)
~~~bash
g++ -std=c++14 stdc++.h
~~~
