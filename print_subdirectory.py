import os

# call this function by passing a directory name
def print_subdirectories(directory_name):
    
    # print the name of the subdirectory directly 
    # within the current directory 
    for filename in os.listdir(directory_name):
        if os.path.isdir(filename):
            path = os.path.join(directory_name, filename)
            print(path)
            
            # one level deeper
            for filename2 in os.listdir(path):
                path2 = os.path.join(path, filename2)
                if os.path.isdir(path2):
                    print(path2)

                # ... ineffective (we need a much more efficient approach) 

# this is where recursion shines, write a script that goes
# arbitrarily deep - with a lot less code
def print_subdirectories_recursive(directory_name):
    for filename in os.listdir(directory_name):
        path = os.path.join(directory_name, filename)
        if os.path.isdir(path):
            print(path)
            print_subdirectories_recursive(path)
            
if __name__ == "__main__":
    print_subdirectories_recursive(".")