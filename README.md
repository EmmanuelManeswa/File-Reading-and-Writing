# File-Reading-and-Writing
It's a C Program that will get two filenames as command line arguments. Opens file #1 for reading and appends the contents of file #1 to file #2.If file #1 doesn't exist it gives a proper error message and if file #2 doesn't exist it creates a new one. After appending it deletes file #1.

The Code exist in read_wrire.c.

Any files can be used as source and destination but in my case I use source.txt and destination.txt.

backup folder contains the same files(source.txt and destination.txt) just in case of running the program again as the source.txt will be deleted.

HOW TO RUN
  1. Requires Unix System(Linux OS or macOS).
  2. In my case all the file are stored in Documents.
  3. Open Terminal in Documents Folder.
  4. Type: gcc -o read_write read_write.c
  5. Then Type: ./read_write ~/Documents/source.txt ~/Documents/destination.txt
  6. All will be done and open destination.txt and you will see that the contents of source.txt will be appended to the file.
  7. Note that source.txt will no longer be there as it will be deleted.
  
