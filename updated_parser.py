import tornado.ioloop, tornado.web, json, os, sys
from colorama import *
minimal_template='#include<bits/stdc++.h> \nusing namespace std;\nvoid solve(){\n\t\n}\nint main()\n{\n\tint test=1;\n\tscanf("%d",&test);\n\tfor(int i=1;i<=test;i++){\n\tsolve();\n\t}\n}'
parsed_problems=[] #contains the parsed problem data
parsed_count=0 #taking input rom console

def make_app():
    return tornado.web.Application([(r"/",MainHandler),])
def done():
    tornado.ioloop.IOLoop.instance().stop()


class MainHandler(tornado.web.RequestHandler):
    def post(self):
        data=json.loads(self.request.body)
        print(data)
        parsed_problems.append(data)
        if len(parsed_problems)==parsed_count:
            done()
            return

def createDirectory(data):
    current_dir=os.getcwd()
    problem_dir=current_dir+'/'+data['name']
    try:
        os.mkdir(problem_dir)
    except FileExistsError:
        print("Folder Already Exists"+data['name'])
        return
    except:
        print(Fore.RED+"An error in Directory creation"+data['name'])
        print(Style.RESET_ALL)
        return

    #create problem file with a template
    problem_file=problem_dir+'/'+data['name']+'.cpp'
    with open(problem_file,'w') as f:
        try:
            with open('template.cpp','r+') as temp_file:
                f.write(temp_file.read())
                temp_file.close()
        except FileNotFoundError:
            print("Template file doesnot exists")
            print("A blanck file has been created")
            f.write(minimal_template)
        except:
            print("Fuck nothing found")
        f.close()
    #creating input output file
    file_input_base=problem_dir+'/input'
    file_output_base=problem_dir+'/output'
    file_cnt=1
    tests=data['tests']
    total_files=len(tests)

    for test in tests:
        print("Creating inout file for "+str(file_cnt))
        with open(file_input_base+str(file_cnt)+'.txt','w') as f:
            f.write(test['input'])
            f.close()
        print("Creating output file for "+str(file_cnt))
        with open(file_output_base+str(file_cnt)+'.txt','w') as f:
            f.write(test['output'])
            f.close()
        file_cnt+=1
    total_files+=1

    #creating another input file for stress testing
    print("Creating another file for testing-> just in case")
    with open(file_input_base+str(total_files)+'.txt','w') as f:
        f.close()


if __name__=="__main__":
    parsed_count=int(input()) #taking input
    app=make_app()
    app.listen(8085)
    tornado.ioloop.IOLoop.current().start()

    print("Creating the test files")
    for data in parsed_problems:
        #print(data)
        createDirectory(data)
    print("All done, Enjoy")
