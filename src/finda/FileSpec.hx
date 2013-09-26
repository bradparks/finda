package finda;

typedef FileSpec =
{
    name: String,
    isDir: Bool,
    firstLetter: Int,
    fileStat: sys.FileStat,
    subDirLen: Int
}