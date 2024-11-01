# Minihell
our awful minishell project from a while back at Hive Helsinki. A "creative" take on bash with a non-library readline implementation, mediocre execution and command chaining.
#Features
conditional command chaining, made with an AST:
```
(./something important && echo "successful") || echo "Failed miserably"
```
simple redirections with pipes, files and heredocs
```
echo "silly" > silly.txt | ls | cat > folder_content
```
wildcards
```
cat */shadow | head -1
```
our very own builtins
```
export a=1
env
unset a=1
```

#ps
it might have a couple of unintended features™ like some undefined behaviour and usage after free
