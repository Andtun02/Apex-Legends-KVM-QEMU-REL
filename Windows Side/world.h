#pragma once
class world {
public:
	ImVec2 w1; //origin of point 1
	ImVec2 w2; //origin of point 2
	ImVec2 s1; //screen coord of point 1
	ImVec2 s2; //screen coord of point 2
	float ratioX;
	float ratioY;

	world(const std::string& fileName) {
		// Open the file
		std::ifstream file(fileName);
		if (!file.is_open()) {
			std::cerr << "Error: Could not open file " << fileName << std::endl;
			return;
		}

		// Read values from the file
		while (file >> std::ws && file.peek() != '#') {
			file >> w1.x >> w1.y >> s1.x >> s1.y >> w2.x >> w2.y >> s2.x >> s2.y;
		}

		// Calculate ratios
		ratioX = (s2.x - s1.x) / (w2.x - w1.x);
		ratioY = (s1.y - s2.y) / (w2.y - w1.y);

		// Close the file
		file.close();
	}
	void loadFromFile(const std::string& fileName) {
		std::ifstream file(fileName);
		if (!file.is_open()) {
			std::cerr << "Error: Could not open file " << fileName << std::endl;
			return;
		}

		while (file >> std::ws && file.peek() != '#') {
			file >> w1.x >> w1.y >> s1.x >> s1.y >> w2.x >> w2.y >> s2.x >> s2.y;
		}

		ratioX = (s2.x - s1.x) / (w2.x - w1.x);
		ratioY = (s1.y - s2.y) / (w2.y - w1.y);

		file.close();
	}
};