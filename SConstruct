env = Environment(tools=['default', 'packaging'])


env.Append(CCFLAGS = Split('-g -ggdb -Wall -Wextra -DBTDEBUG'))
#env.Append(CCFLAGS = Split('-g -O2 -Wall -Wextra -DNDEBUG'))

#set include path
comroot='../../../com/'
cpppath=[
    './',
    comroot+'thirdparty/gflags-2.0/include',
    comroot+'thirdparty/glog-0.3.3/include',
    comroot+'thirdparty/gtest-1.6.0/include',
];
env.Append(CPPPATH = cpppath)

#set libpath
libpath=[
    './',
    comroot+'thirdparty/gflags-2.0/lib/',
    comroot+'thirdparty/glog-0.3.3/lib/',
    comroot+'thirdparty/gtest-1.6.0/lib/',
    comroot+'thirdparty/boost_1.52.0/lib/',
];
env.Append(LIBPATH = libpath)

#set libs
libs=['gflags', 'gtest', 'glog']
env.Append(LIBS = libs)
Export("env")

import os
import shutil

all_path = [
];

main_path = [
    #'sort',
    '6',
    '8',
];

def FindTestSource(paths):
  objs = []
  for path in paths:
    for file in os.listdir(path):
      if file[-2:] != ".c" and file[-3:] != ".cc" and file[-4:] != ".cpp":
        continue
      if file.startswith("test_"):
        file = '%s/%s' % (path, file)
        objs.append(file)
  return objs

def FindSource(paths):
  objs = []
  for path in paths:
    for file in os.listdir(path):
      if file[-2:] != ".c" and file[-3:] != ".cc" and file[-4:] != ".cpp":
        continue
      if not file.startswith("test_"):
        file = '%s/%s' % (path, file)
        objs.append(file)
  return objs

for bin_source in FindSource(main_path):
    bin_name, suffix = bin_source.split('.')
    if suffix == 'c' or suffix == 'cc' or suffix == 'cpp':
        env.Program(target = bin_name, source = [bin_source] + FindSource(all_path))

for bin_source in FindTestSource(all_path):
    bin_name = bin_source.split('.')[0]
    env.Program(target = bin_name, source = [bin_source] + FindSource(all_path))
