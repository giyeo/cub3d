import os
import re
dir_name = "./cub_files"
test_files = os.listdir(dir_name)
os.system("make re")

def open_test_files(buffer, command):
	assert buffer.count('OK') == 4 # 4 files were opened
	print("open_test_files OK:" + command)

def match_wrote_values(buffer, file):
	if(file == '1_simple.cub'):
		assert buffer.contains('F 220,100,0', 'C 225,30,0')

for each in test_files:
	command = "./cube3d " + dir_name + "/" + each
	#os.system(command)
	buffer = os.popen(command).read()
	open_test_files(buffer, command)
	#match_wrote_values(buffer, each)
