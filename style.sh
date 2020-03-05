astyle --ascii --add-braces --break-one-line-headers  --align-pointer=name --pad-comma --unpad-paren  --pad-header --pad-oper --max-code-length=132  --convert-tabs --indent=spaces=4  --indent-continuation=1 --indent-switches  --lineend=linux --min-conditional-indent=1  --options=none --style=allman "$1"

for i; do 
    echo $i 
 done
