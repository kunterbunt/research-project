function values = getValuesFromFile(filename)
fileID = fopen(filename, 'r');
formatSpec = '%f';
values = fscanf(fileID, formatSpec);
fclose(fileID);
end