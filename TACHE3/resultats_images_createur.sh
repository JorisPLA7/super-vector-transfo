if [ $# -eq 2 ]
then

  for image in $1*
  do
    echo "execution sur $image" 
    ./transfo_vecteur $image $2
  done

else 

  echo "$0 <repertoire images> <fichier de sortie>"
fi
