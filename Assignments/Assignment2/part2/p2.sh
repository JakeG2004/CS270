# Change arguments to be more readable
fileName=$1

if [ "$fileName" = "" ]
then
	echo "Invalid usage! ./p2.sh <fileName>"
	exit
fi

# Check for file existence
fileExists=`ls $fileName 2>/dev/null | wc -l`

# Ensure that the file exists
if [ $fileExists -eq 0 ]
then
	echo "File $fileName doesn't exist!"
	exit
fi

# Convert name to lowercase
lowerCaseFileName=`echo "$fileName" | tr '[:upper:]' '[:lower:]'`

# Cut the underscores from the filename
finalName=${lowerCaseFileName//_}

# Ensure that new file won't overwrite an old one
fileExists=`ls $finalName 2>/dev/null | wc -l`

if [ $fileExists -gt 0 ]
then
	echo "File $finalName already exists!"
	exit
fi

# Move the file
mv $fileName $finalName
