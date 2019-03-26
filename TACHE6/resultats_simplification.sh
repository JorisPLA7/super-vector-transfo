if [ $# -eq 3 ]
then

  for image in $1*
  do
    #echo "execution sur $image , sorties sur $2/$image.eps"  
    ./t6_simplification $image $2/$(basename $image) $3
  done

else 

  echo "$0 <repertoire images> <repertoire de sortie> <finesse d>"
fi
