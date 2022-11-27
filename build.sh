#!/usr/bin/bash

sbt clean dist

cp /home/pwh/MPPatch/target/dist/mppatch* /mnt/hgfs/SHARED/
