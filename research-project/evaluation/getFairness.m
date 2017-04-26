function fairness = getFairness(values)
fairness = (sum(values)^2) / (size(values, 2) * sum(values.^2));
end

