# Make arguments have better names
fileName=$1					# Get filename from CLI
arg=$2						# get second argument

# Clear out.txt
> out.txt					# clear out.txt

# Test that the filename exists
if [ "$fileName" = "" ]
then
	echo "Invalid argument! usage: p1 <filename> <-a> <-r>"
	exit
fi

# Test that argument exists
if [ "$arg" = "" ]
then
	echo "Invalid argument! usage: p1 <filename> <-a> <-r>"
	exit
fi

# Flag for whether the file exists or not
fileExists=`ls $fileName 2>/dev/null | wc -l`

# Test that file exists
if [ $fileExists -eq 0 ]			# test that the file exists
then
	echo "File does not exist: $fileName"
	exit
fi

# Handle "append mode" (adding characters)
if [ "$arg" = "-a" ]
then
	lineCount=`cat $fileName | wc -l`		# get line count of file

	for ((i=1;i<lineCount+1;i++))			# for each line of the file
	do
		curLine="$i `head -$i $fileName | tail +$i`" # get line and add number
		echo "$curLine" >> out.txt		# append the current line to an outfile
	done
	exit
fi

# Handle "remove mode" (remove characters)
if [ "$arg" = "-r" ]
then
	lineCount=`cat $fileName | wc -l`
	
	for ((i=1;i<lineCount+1;i++))
	do
		curLine=`head -$i $fileName | tail +$i` # get current line
		echo "${curLine#* }" >> out.txt		# write everything following the first space to the outfile
	done
	exit
fi

echo "Invalid argument! usage: p1 <filename> <-a> <-r>"
