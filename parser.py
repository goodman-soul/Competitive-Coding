import tornado.ioloop
import tornado.web
import json
import os
from colorama import *
import sys

class MainHandler(tornado.web.RequestHandler):
    def post(self):
        data = json.loads(self.request.body)
        createDirectory(data)

def make_app():
    return tornado.web.Application([
        (r"/", MainHandler),
    ])

def createDirectory(data):
    current_dir = os.getcwd()
    problem_dir = current_dir + '/' + data['name']
    try:
        os.mkdir(problem_dir)
    except FileExistsError:
        print(Fore.RED + "Folder Exists " + data['name'])
        print(Style.RESET_ALL)
    except:
        print(Fore.RED + "An error occured while creating the directory" + data['name'])
        print(Style.RESET_ALL)

    problem_file = problem_dir + '/' + data['name'] + '.cpp'
    with open(problem_file, 'w') as f:
        f.close()

    file_input_base = problem_dir + '/input'
    file_output_base = problem_dir + '/output'
    file_now = 1
    tests = data['tests']
    total_files = len(tests)
    for test in tests:
        print(Fore.GREEN + "Creating test file " + str(file_now))
        print(Style.RESET_ALL)
        with open(file_input_base+str(file_now)+'.txt', 'w') as f:
            f.write(test['input'])
            f.close()
        with open(file_output_base+str(file_now)+'.txt', 'w') as f:
            f.write(test['output'])
            f.close()
        file_now+=1

    total_files+=1
    with open(file_input_base+str(total_files)+'.txt', 'w') as f:
            f.close()

    print(Fore.GREEN + "All Done")
    print("===============================\n")
    print(Style.RESET_ALL)

def done_all():
    tornado.ioloop.IOLoop.instance().stop()

if __name__ == "__main__":
    app = make_app()
    app.listen(8085)
    tornado.ioloop.IOLoop.current().start()
