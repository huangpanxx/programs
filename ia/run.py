#!/usr/bin/env python
#coding:utf8
import sys
import os
if len(sys.argv) == 2:
	cpp = sys.argv[1]
	os.system('g++ ' + cpp  + ' -o a.out && ./a.out && rm -rf a.out')
