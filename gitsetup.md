***Source-> geekforgeeks***
### Create Github Account
1. Installing Git->
at first install snap & then install git-ubuntu
~~~bash
sudo snap install git-ubuntu --classic
~~~
2. Git Configuration
~~~bash
$ git config --global user.name "your username"
$ git config --global user.email "your_email"
~~~
3. Go to project folder & open the terminal 
~~~bash
$ git remote add origin https://github.com/<your_username>/<myproject>.git
$ git add <file_name>
$ git push origin master
or
~~~
Note: this master can be anything->creating a pull request.

to Delete files/folders:-
~~~bash
$ git checkout master
$ git rm -r <folder name>
$ git commit -m "remove folder"
$ git push origin master
~~~

if face some problems-> something like (git pull ....)
simply do 
~~~bash
git pull
~~~
then try to push it again.
