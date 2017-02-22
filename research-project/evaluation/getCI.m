function CI = getCI(meansVec, alpha)

m = length(meansVec);
sampleMean=mean(meansVec); %Mean

sampleVariance=0; %Variance
for i=1:m
    sampleVariance=(meansVec(i)-sampleMean)^2+sampleVariance;
end
sampleVariance=sampleVariance/(m-1);

deviation=sqrt(sampleVariance); %Deviation

mu = 0; %Normal Distribution
sigma = 1;
y=1-alpha;
Z=icdf('Normal',y,mu,sigma); 

CI=[sampleMean-Z*deviation/sqrt(m),sampleMean+Z*deviation/sqrt(m)];
end
