# APFS Stuff

1. APFS Container

- Imports APFS Physical stores
- Exports APFS Volumes
- Named by a particular physical store
  + Called the container reference disk
- (Only supports 1:1 mapping between physical stores and volumes for now)

2. Managing disks

- `diskutil apfs -IHaveBeenWarnedThatAPFSIsPreReleaseAndThatIMayLoseData`
- Aliased by `apfs` on my laptop

3. Create container

- `apfs createContainer diskXsY`
- `apfs list` shows global APFS state
- One container, one physical store

4. Create Volume

- `apfs addVolume diskXsY APFS MyVolume`
  + Space-sharing by default
  + Space-sharing volumes will share storage of underlying container
  + May result in surprising out-of-space errors
- `apfs addVolume diskXsY APFS MyFixedVolume 10g`
  + Fixed-size volume
  + Can't grow beyond original size
  + Guaranteed to have as much space as originally allocated

5. Play around with features

- `dd if=/dev/random of=bigfile bs=1m count=512`
- `clone bigfile bigfile.2`
  + `du -ch .` reports 1GB of data, `apfs list` reports ~512M of usage!
- `for i in $(seq 500); do clone bigfile "bigfile.tmp.${i}"; done;`
  + 251G vs ~512M!!
- Change first block
  + `modify bigfile`
  + Space doesn't increase much, most blocks unchanged
- Prepend to file
  + `vim bigfile`, insert character
  + Space increases a ton, all blocks after edit have been modified
- New atomic swap operation
  + `swap bigfile bigfile.tmp.2`
  + Claimed to be atomic by Apple

6. Implementation

- Copy-on-write
  + Clone operation creates file with references to old blocks
  + Only create copy of a block when it's modified
  + Saves space when performing lots of copies
  + Very different from hard link
    * Modifying hard-linked file changes original
    * Modifying COWed file creates copy, original stays same

7. Other things

- Snapshotting and Revisioning?
  + Doesn't seem to be available yet
  + No mention of either in man pages
- Encryption
  + Lots of encryption / privacy features
  + Fast erase: Give `eff` option to `apfs addVolume`
    * Not really encryption
    * How might it be implemented?
    * Doesn't work yet as far as I can tell
  + Per volume, per file, encryption

