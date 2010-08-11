NAME
----

node-processctl - Process control addon for node

SYNOPSIS
--------

  var pctl = require('processctl');
  var child_pid = pctl.fork();
  if(child_pid) {
    sys.puts("I'm the parent");
  } else {
    sys.puts("I'm the child");
  }

BUILDING
--------

To build the bindings:

    git clone git://github.com/konobi/node-processctl.git
    cd node-processctl
    node-waf configure build

TESTS
-----

Running the unit tests could not be easier. Simply:

    NODE_PATH=. node fork_test.js

AUTHORS
-------

Scott McWhirter [scott+node-processctl@konobi.co.uk]

LICENSE
-------

node-processctl is BSD licensed.

(c) 2010 Joyent Inc.
