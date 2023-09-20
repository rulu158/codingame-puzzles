# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

read -r N
horsesPower=( )
for (( i=0; i<$N; i++ )); do
    read -r Pi
    horsesPower+=($Pi)
done

readarray -d '' sortedHorsesPower < <(printf '%s\0' "${horsesPower[@]}" | sort -zn)

minDiff=0
for i in ${!sortedHorsesPower[@]}; do
    if [[ $i -eq 0 ]]; then
        continue
    fi
    diff=$((${sortedHorsesPower[$i]}-${sortedHorsesPower[$i-1]}))
    if [[ $i -eq 1 || $diff -lt $minDiff ]]; then
        minDiff=$diff
    fi
done

# Write an answer using echo
# To debug: echo "Debug messages..." >&2

echo $minDiff
