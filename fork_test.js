#!/usr/bin/env node

var sys = require('sys');
var process_ctl = require('processctl');

sys.puts("Parent PID is: "+process.pid);
var parent_pid = process.pid;

var child_pid = process_ctl.fork();
if(child_pid) {
    sys.puts("Parent thinks child is: "+child_pid);
    process.exit(0);
} else {
    sys.puts("Child PID is: "+process.pid);
    process.exit(0);
}

