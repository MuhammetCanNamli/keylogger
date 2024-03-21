try:
    with open("keymaps.txt", "r") as keymap:
        keymap_linelist = keymap.readlines()
except FileNotFoundError:
    print("File not found.")
except Exception as e:
    print(f"Something went wrong: {e}")

# It reads the file named 'log.txt' and assigns its contents as a list to the keylogger_linelist variable.
# Since we created the 'log.txt' file ourselves, we do not need to check it with try commands.
keylogger = open("log.txt", "r")
keylogger_linelist = keylogger.readlines()
keylogger.close() # The reason we close files is to free up resources so that the files can be safely terminated.


# An empty dictionary is created.
keymap_list = {}


# This loop will create a list of Keymaps. (in keycode:key notation)
for i in keymap_linelist:
    # Separation is done according to the spaces in the line.
    i = i.split()
    i = i = [item.strip() for item in i]
    l = len(i)

    # A condition expression is used based on the length of the line.
    if(l == 4):
        # If the length of the line is 4, the second element (i[1]) is added to the dictionary as the key and the fourth element (i[3]) is added as the value.
        keymap_list[i[1]] = i[3]
    elif(l == 5): 
        # If the length of the line is 5, the third element (i[2]) is added to the dictionary as the key and the fifth element (i[4]) is added as the value.
        keymap_list[i[2]] = i[4]
    else: 
        # If the length of the line is not 4 or 5, it continues the loop.
        continue


key_list = keymap_list.keys() # Creates a list by taking the keys parameters in keymap_list.
ekey_list = [] # An empty list is created.

st = 0 # The variable st is initially assigned to 0.

# Creates a loop that loops over each line in the keylogger_linelist.
for j in keylogger_linelist:
    # Separation is done according to the spaces in the line.
    j = j.split()
    l = len(j)

    # Conditional operations are performed according to the length of the line.
    if l == 3:
        # If the length of the row is 3 and the second element is 14 and ekey_list is not empty, remove the last element from ekey_list.
        if j[1] == '14' and len(ekey_list) != 0:
            ekey_list.pop()
        elif j[2] == 'release':
            # If the third element of the row is 'release'
            if j[1] == '42' and st == 1:
                # If the second element is 42 and st is 1, 42 is added to ekey_list, making st 0 and adding '<released>'.
                ekey_list.append(j[1])
                st = 0
                ekey_list.append('<released>')
            else:
                # Otherwise, it continues the cycle.
                continue
        else:
            # If the above conditions are not met, actions are taken according to the following conditions.
            if j[1] == '42' and st == 1:
                # If the second element is 42 and st is 1, it continues the loop.
                continue
            elif j[1] == '42' and st == 0:
                # If the second element is 42 and st is 0, 42 and '<pressed>' are added to ekey_list, making st 1.	
                ekey_list.append(j[1])
                ekey_list.append('<pressed>')
                st=1
            elif j[1] != '42':
                # If the second element is not 42, the second element is added to ekey_list.
                ekey_list.append(j[1])
            else:
                # Otherwise, it continues the cycle.
                continue

# ekey_list is created with the login codes in the log.txt file.
# ekey_list contains the pressed and released status of keyboard inputs.


# Keycodes are decoded using the keymap_list dictionary and written to the file named output.log.


with open("output.log", "w") as output: # w means write. If there is no such file, it creates it. If there is, it deletes it and creates a new one.
    for x in ekey_list:
        for y in key_list:
            if x == y and y in keymap_list:
                # If x matches a key in key_list, its value in keymap_list is written to the output.log file.
                output.write(keymap_list[y])
        if x == '<pressed>':
            # If x is '<pressed>', '<pressed>' is written to the output.log file.
            output.write('<pressed>')
        elif x == '<released>':
            # If x is '<released>', '<released>' is written to the output.log file.
            output.write('<released>')

        output.write("\n")

            
output.close()
