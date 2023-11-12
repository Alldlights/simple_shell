<h1>Simple Shell (BASH sheel replica)<h1><br>
A simple shell implementation in C.<br>

<p>Overview<p>
<ul>
<l1>List of allowed functions and system calls<li>
<li>access (man 2 access)<li>
<li>chdir (man 2 chdir)<li>
<li>close (man 2 close)<li>
<li>closedir (man 3 closedir)<li>
<li>execve (man 2 execve)<li>
<li>exit (man 3 exit)<li>
<li>_exit (man 2 _exit)<li>
<li>fflush (man 3 fflush)<li>
<li>fork (man 2 fork)<li>
<li>free (man 3 free)<li>
<li>getcwd (man 3 getcwd)<li>
<li>getline (man 3 getline)<li>
<li>getpid (man 2 getpid)<li>
<li>isatty (man 3 isatty)<li>
<li>kill (man 2 kill)<li>
<li>malloc (man 3 malloc)<li>
<li>open (man 2 open)<li>
<li>opendir (man 3 opendir)<li>
<li>perror (man 3 perror)<li>
<li>read (man 2 read)<li>
<li>readdir (man 3 readdir)<li>
<li>signal (man 2 signal)<li>
<li>stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

Compilation
Your shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 


