struct Result {
    float avg[3];
};

/*
This is the function you need to implement. Quick reference:
- x coordinates: 0 <= x < nx
- y coordinates: 0 <= y < ny
- horizontal position: 0 <= x0 < x1 <= nx
- vertical position: 0 <= y0 < y1 <= ny
- color components: 0 <= c < 3
- input: data[c + 3 * x + 3 * nx * y]
- output: avg[c]
*/
Result calculate(int ny, int nx, const float *data, int y0, int x0, int y1, int x1) {
    Result result{{0.0f, 0.0f, 0.0f}};  // Initialize the result with zeros
    int totalPixels = (y1 - y0) * (x1 - x0);  // Calculate the total number of pixels in the rectangle

    // Use double for intermediate calculations to improve precision
    double sum[3] = {0.0, 0.0, 0.0};

    // Loop through the rectangle
    for (int y = y0; y < y1; ++y) {
        for (int x = x0; x < x1; ++x) {
            // Loop through each color component
            for (int c = 0; c < 3; ++c) {
                // Calculate the index for the current pixel and color component
                int index = c + 3 * x + 3 * nx * y;
                
                // Add the color component value to the running sum
                sum[c] += static_cast<double>(data[index]);
            }
        }
    }

    // Calculate the average for each color component
    for (int c = 0; c < 3; ++c) {
        result.avg[c] = static_cast<float>(sum[c] / static_cast<double>(totalPixels));
    }

    return result;
}
