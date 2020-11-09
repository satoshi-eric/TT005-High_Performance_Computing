for i in 1 2 3;
do
    size=$((10**${i}))
    command=" ${size} ${size} ${size} "

    for j in "A" "B" "C";
    do
        filename=arq${j}${size}x${size}.dat
        command+="${filename} " 
    done
    command+=arqD${size}x${size}.dat
    time ./programa ${command} > time${size}.txt
    time ./semOmp ${command} > time${size}sem.txt
done