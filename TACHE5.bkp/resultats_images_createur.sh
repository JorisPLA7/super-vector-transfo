if [ $# -eq 2 ]
then

  for image in $1*
  do
    echo "execution sur $image , sorties sur $2/$image.eps"  
    ./transfo_vecteur $image $2/$(basename $image) 
  done

else 

  echo "$0 <repertoire images> <repertoire de sortie>"
fi