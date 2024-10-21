# Get directory
src=$1

# Check for empty argument
if [ "$src" = "" ]
then
    echo "Improper usage! ./backup <source directory>"
    exit
fi

# Flag for whether the directory exists or not
fileExists=`ls $src 2>/dev/null | wc -l`

# Test that directory exists
if [ $fileExists -eq 0 ]
then
	echo "Directory does not exist: $src"
	exit
fi

# Make sure that .backup exists
mkdir .backup 2>/dev/null

# Get all of the files in the source directory
filesToCopy=`ls $src`

# Process each file
for file in $filesToCopy
do
    # Check if file exists in .backup
    fileExists=`ls .backup/$file 2>/dev/null | wc -l`

    # Handle the two cases
    if [ $fileExists -gt 0 ]
    then
        # Prompt user for input regarding the file
        echo "File $file exists in .backup. Would you like to overwrite? (y/n)"

        # Get the input
        read input

        while [ "$input" != "y" ] && [ "$input" != "n" ]
        do
            echo "Input must be \"y\" or \"n\""
            read input
        done


        # Handle overwrite
        if [ "$input" = "y" ]
        then
            echo "Overwriting $file..."
            cp -r $src/$file .backup
        fi

    # Copy if no conflict
    else
        cp -r $src/$file .backup
    fi
done