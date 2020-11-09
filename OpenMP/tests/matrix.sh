<< Information

Nome: Eric Satoshi Suzuki kishimoto
Data: 09/11/2020
Script para gerar matrizes a partir do programa generate random matrix

Information

for i in 1 2 3;
do
    for j in "A" "B" "C";
    do
        size=$((10**${i}))
        filename=arq${j}${size}x${size}.dat
        ./generateRandomMatrix ${size} ${size} 0 ${size} ${filename}
        echo ${filename}
    done
done