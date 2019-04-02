time if [ $# -eq 3 ]
then

  for image in $1*
  do
    for mode in s b1 b2
    do
        for precision in 0 0.5 1 2 4 8 16
        do
            #echo "execution sur $image , sorties sur $2/$image.eps"  
            ./t7_simplif_douglas_bezier $image $2/$(basename $image)_$mode_$precision $3 $4
        done
    done
done

else 

  echo "$0 <repertoire images> <repertoire de sortie> <s, b2, b3> <precision>"
fi
