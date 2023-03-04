---
title: SSTOOLS
section: 1
header: User Manual
footer: sstools 0.2b
date: March 04, 2023
---


# NAME

sstools - KISS tools for make snapshots in a Btrfs filesystem

# SYNOPSYS

**sstd**

**ssmk** [*-vh*] *-i* subvolume *-o* pool *-f* frequency

**sscl** [*-vh*] *-p* pool *-q* quota

**ssct** [*-h*] [*-v*] path


# DESCRIPTION

SSTools is made up of several small programs that work together, functioning
as one.

## Currently main tools

- _sstd_: Snapshot tools daemon.
- _ssmk_: For making snapshots.
- _sscl_: For cleaning snapshots.

## Additional tools

Additionally, it also integrates the following tools:

- _ssct_: Shows creation and changed time a snapshot.

## Not implemented yet tools

- _ssst: Shows some statics of interest.
- _ssgui_: Graphic user interface.


## Basic operation

On startup **sstd** loads `/etc/sstab` (see sstab(5)) into memory and
periodically creates or deletes snapshots in the specified _pool_
directory.

For this task a systemd service file is provided.

Edit `/etc/sstab` at your preferences and then start and enable
`sstd.service`.

### `/etc/sstab`

A simple table, named `/etc/sstab` is provided as configuration file.

The configuration file defines all the stuff about
what and how the snapshots of subvolumes are taked.
Read  more about it in snapman(5).

#### Example file:


    # subvolume    pool               frequency    quota
 
    /              /backup/root/boot  0            30
    /              /backup/root/diary 1d           30
    /home          /backup/home/30m   30m          20


In every execution loop, if more time than indicated by the
_frequency_ has passed, a new snapshot of the _subvolume_ will be
created inside of its own _pool_, until reach the _quota_, and then,
when quota were overpassed, it will deletes the oldest snapshot until
fit to the quota.

# INCLUDED TOOLS

## sstd

Is the daemon. Loads `/etc/sstab` into memory and starts an infinite
loop where firstly runs `ssmk` and then `sscl` for each line of such file.

The loop repeats itself every 5 seconds.

## ssmk

Takes a source soubvolume and creates a snapshot and a destination
directory (called pool), where previous snapshots were stored.

Checks if the last snapshot in such pool is enough old and if there
are differences with source subvolume, and then takes a new snapshot.

The snapshot name is automatically set in the `date` format
**`+%Y-%m-%d_%H-%M-%S`**.


## sscl

Takes a pool directory and checks if there are more snapshots than
indicated as maximum by the quota. If then, deletes the oldest snapshots until the quota is met.

## ssct

Shows when subvolume was created and when an inode in the subvolume
was last change.

# NOT YET IMPLEMENTED/INCLUDED TOOLS

## ssst

Show snapshot statistics.

## ssgui

Graphic user interface.

---

# _TODO_

- Signals handling.

# SEE ALSO

sstab(5)
	
# AUTHOR

Manuel Domínguez López <mdomlopatgmaildotcom>
	
# COPYRIGHT

GPLv3