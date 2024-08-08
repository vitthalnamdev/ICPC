g++ my_solution.cpp -o my_solution
g++ bruteForce_solution.cpp -o bruteForce_solution
g++ randomTestGenerator.cpp -o randomTestGenerator

for((i = 1; ; ++i)); do
    ./generator $i > randomInput
    ./wrong <randomInput > WA
    ./correct <randomInput > AC
    diff -w WA AC || break
    echo "Passed test: "  $i
done

echo -e "\nWA on the following test:"
cat randomInput
echo "Your answer is:"
cat WA
echo "Correct answer is:"
cat AC