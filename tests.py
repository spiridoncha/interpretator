import commands
import difflib

path = 'test/'
tmp = 'tmp.txt'
files = filter(lambda x:x[-4:] != '_res', map(lambda x:path+x, (commands.getoutput('ls '+path)).split('\n')))
for f in files:
    with open(tmp, 'w') as tmp_file:
        tmp_file.write(commands.getoutput('./eduLang '+f))
    with open(tmp, 'r') as tmp_file:
        with open(f+'_res', 'r') as fl:
            tm = map(lambda x:x.rstrip(), tmp_file.readlines())
            fl1 = map(lambda x:x.rstrip(), fl.readlines())
            if tm == fl1:
                print 'O.K. in ' + f
            else:
                print 'Problem in ' + f
commands.getoutput('rm '+tmp)
