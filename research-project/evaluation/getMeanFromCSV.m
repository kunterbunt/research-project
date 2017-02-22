function [observed_mean CI] = getMeanFromCSV(filename, numberOfRuns)
    observed_values = csvread(filename);
    meansVec = [];
    j = 1;    
    for i = 0:numberOfRuns:length(observed_values) - numberOfRuns
        from = i + 1;
        to = from + numberOfRuns - 1;
        runMean = mean(observed_values(from:to));
        meansVec = [meansVec; runMean]; % Holds mean of each run.
    end
    CI = getCI(meansVec, 0.05);
    observed_mean = mean(meansVec); % Holds average mean of all runs.
end