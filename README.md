# nobodyexec

A dead simple tool to setuid,setgid and exec.

## Usage

```bash
./nobodyexec id
uid=99(nobody) gid=99(nogroup) groups=99(nogroup)
```

## Compare to sudo -u nobody xxx

No fork, no login shell, don't change any environment variables.