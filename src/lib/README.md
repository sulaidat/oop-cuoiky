# Usage 

Parse `line` (in CSV format) and store in `values`:

```c
    ParseError parseLine(const string &line, vector<string> &values);
```

Write `values` to string `line` (in CSV format)

```c
    string writeLine(const vector<string> &values);
```

# Accepted Format

Without quotes:
```
1,2,3   ->  [1,2,3]
```

With a pair of quote:
```
"tuyen",2,3 -> ["tuyen",2,3]
```

With inner qoutes, inner quote must be a pair at once `""`, and one quote will be trimmed while parsing into values:
```
"tuyen ""dep trai""",2,3 -> ["tuyen "dep trai"",2,3]
```