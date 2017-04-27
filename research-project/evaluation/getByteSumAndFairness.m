function [byteSum, fairness] = getByteSumAndFairness(filename)
    values = getValuesFromFile(filename);
    byteSum = sum(values);
    fairness = getFairness(values');
end

