for i in 1 2 3;
do
    size=$((10**${i}))
    command="./"programa" ${size} ${size} ${size} "

    for j in "A" "B" "C";
    do
        filename=arq${j}${size}x${size}.dat
        command+="${filename} " 
    done
    command+=arqD${size}x${size}.dat
    time ${command} > time${size}.txt
done