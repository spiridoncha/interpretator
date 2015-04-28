import os
import commands
import filecmp

path = 'test/'
tmp = 'tmp.txt'
files = filter(lambda x:x[-4:] != '_res', map(lambda x:path+x, (commands.getoutput('ls '+path)).split('\n')))
for f in files:
    with open(tmp, 'w') as tmp_file:
        tmp_file.write(commands.getoutput('./eduLang '+f))
    if filecmp.cmp(tmp, f+'_res'):
        print 'O.K. in ' + f
    else:
        print 'Problem in ' + f
commands.getoutput('rm '+tmp)
