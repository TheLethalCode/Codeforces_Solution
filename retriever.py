import requests as rq
import os, sys
from time import sleep

README = "README.md"

RENEW = """# Codeforces_Solution
Program codes for a wide range of Codeforces problem (constantly updating)

## PROBLEMS
"""

# Key function for sorting
def sort_key(elem):
    return "{:05d}{}".format(elem[0],elem[1])


# Clear Readme file
def clear_readme():
    with open(README,"w") as op:
        op.write(RENEW)


# Find the problems already present in the readme file 
def alread_present():

    problems = []
    with open(README, "r") as op:
        for item in op.readlines():
            if item[0]=='-':
                ind = item.find(":")
                a, b = item[4:ind].split("-")
                problems.append(a+b+".cpp")
    return problems


# Find the name of the the problem corresponding to the code
def find_name(prob):

    baseURL = "https://codeforces.com/problemset/problem/"
    START = "<div class=\"title\">"
    END = "</div>"

    URL = baseURL + prob[0]+"/"+prob[1]
    request = rq.get(URL)
    page = request.text
    ind = page.find(START)
    page = page[ind+len(START)+2:]
    ind = page.find(END)
    name = page[:ind].strip()
    if name[0] == '.':
        name = name[1:].strip()
    return name


# Append names
def append_name(prob, name):
    
    with open(README, "a+") as op:
        op.write("- **{}-{}:** {}\n".format(prob[0], prob[1], name))


# Find names of new problems and append it to readme
def find_names(files):
    
    for file in files:
        for ind, el in enumerate(file):
            if not el.isdigit():
                item = (file[:ind], file[ind:])
                name = find_name(item)
                append_name(item, name)
                print("- {}-{}: {}".format(item[0], item[1], name))
                break
    

# Sort the problems in the readme
def sort_readme():
    
    problems = []
    with open(README) as op:
        for item in op.readlines():
            if item[0]=='-':
                ind = item.find(":")
                a, b = item[4:ind].split("-")
                c = item[ind+4:-1]
                problems.append((int(a), b, c))

    problems.sort(key=sort_key)
    clear_readme()
    
    for problem in problems:
        append_name((problem[0], problem[1]), problem[2])


if __name__ == '__main__':
    
    # Rewrite readme if given the option
    if len(sys.argv) == 2:
        if sys.argv[1] == "clear":
            clear_readme()
    
    # Find Names of already present problem in readme
    prev = alread_present()

    # Get the new problems to update
    files = [it[:-4] for it in os.listdir(".") if (".cpp" in it) and (it not in prev)]

    # Update readme
    find_names(files)
    
    sort_readme()
    # for key in name:
    #     print("{}-{}: {}".format(key[0], key[1], name[key]))
    
