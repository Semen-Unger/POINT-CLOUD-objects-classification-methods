#include "fractalDimension.h"

// вариант 1
Point3D computeOrtoCenter(const vector<Point3D>& points) { //min max
    double minX = 0.0, minY = 0.0, minZ = 0.0;
    double maxX = 0.0, maxY = 0.0, maxZ = 0.0;
    for (const auto& p : points) {
        if (minX >= p.x) { minX = p.x; }
        if (minY >= p.y) { minY = p.y; }
        if (minZ >= p.z) { minZ = p.z; }
        if (maxX <= p.x) { maxX = p.x; }
        if (maxY <= p.y) { maxY = p.y; }
        if (maxZ <= p.z) { maxZ = p.z; } //min max
    }
    return Point3D((minX + maxX) * 0.5, (minY + maxY) * 0.5, (minZ + maxZ) * 0.5);
}

// Функция вычисления расстояний
double computeLeights(const vector<Point3D>& points) {
    double minX = 0.0, minY = 0.0, minZ = 0.0;
    double maxX = 0.0, maxY = 0.0, maxZ = 0.0;
    for (const auto& p : points) {
        if (minX >= p.x) { minX = p.x; }
        if (minY >= p.y) { minY = p.y; }
        if (minZ >= p.z) { minZ = p.z; }
        if (maxX <= p.x) { maxX = p.x; }
        if (maxY <= p.y) { maxY = p.y; }
        if (maxZ <= p.z) { maxZ = p.z; }
    }
    Point3D maxmin = Point3D(fabs(minX - maxX), fabs(minY - maxY), fabs(minZ - maxZ));
    if (maxmin.x > maxmin.y) {
        if (maxmin.x > maxmin.z) { return maxmin.x * 0.5; }
        else { return maxmin.z * 0.5; }
    }
    else {
        if (maxmin.y > maxmin.z) { return maxmin.y * 0.5; }
        else { return maxmin.z * 0.5; }
    }
}


// вариант 2
// Функция вычисления центра масс
Point3D computeCenter(const vector<Point3D>& points) {
    double sumX = 0.0, sumY = 0.0, sumZ = 0.0;
    for (const auto& p : points) {
        sumX += p.x;
        sumY += p.y;
        sumZ += p.z;
    }
    return Point3D(sumX / points.size(), sumY / points.size(), sumZ / points.size());
}

// Функция вычисления максимального расстояния от центра до точек
double computeMaxDistance(const vector<Point3D>& points, const Point3D& center) {
    double maxDist = 0.0;
    for (const auto& p : points) {
        double dist = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2) + pow(p.z - center.z, 2));
        if (dist > maxDist) maxDist = dist;
    }
    return maxDist;
}



// Расчёт фракатльной размерности с помощью геометрического центра и расстояния
double computeFractalDimensionGeometry(const vector<Point3D>& points, int numScales) {
    if (points.empty()) return 0.0;

    // 1. Находим центр и максимальное расстояние

    // В этом блоке необходимо использовать либо раскоменченные две функции: (computeCenter and computeMaxDistance), либо закоменченные две функции: (computeOrtoCenter and computeleights), не перемешивая их между собой.
    Point3D center = computeOrtoCenter(points);
    double maxDist = computeLeights(points);
    //Point3D center = computeOrtoCenter(points);
    //double maxDist = computeleights(points);

    // 2. Подготавливаем размеры ячеек
    vector<double> epsilons;
    for (int i = 0; i < numScales; ++i) { double epsilon = maxDist / pow(2, i); epsilons.push_back(epsilon); }

    // 3. Для каждого epsilon считаем число занятых ячеек
    vector<int> total_count;

    for (double epsilon : epsilons) {
        if (epsilon <= 0.0) continue;
        using Voxel = tuple<int, int, int>;
        set<Voxel> Voxels;
        for (const auto& point : points) {
            int Lx = (point.x - (center.x - maxDist)) / epsilon;
            int Ly = (point.y - (center.y - maxDist)) / epsilon;
            int Lz = (point.z - (center.z - maxDist)) / epsilon;
        Voxels.insert({ Lx, Ly, Lz });
        }
        total_count.push_back((int)Voxels.size());
    }


    // 4. Линейная регрессия для log(N) vs log(1/epsilon)
    double sumLogN = 0.0, sumLogInvEps = 0.0, sumLogNLogInvEps = 0.0, sumLogInvEpsSq = 0.0;
    for (int i = 0; i < numScales; ++i) {

        double logN = log(total_count[i]);
        double logInvEps = log(1.0 / epsilons[i]);

        sumLogN += logN;
        sumLogInvEps += logInvEps;
        sumLogNLogInvEps += logN * logInvEps;
        sumLogInvEpsSq += logInvEps * logInvEps;
    }

    double D = (numScales * sumLogNLogInvEps - sumLogN * sumLogInvEps) / (numScales * sumLogInvEpsSq - sumLogInvEps * sumLogInvEps);
    return D;
}


// Расчёт фракатльной размерности с помощью центра масс и расстояния
double computeFractalDimensionMass(const vector<Point3D>& points, int numScales) {
    if (points.empty()) return 0.0;

    // 1. Находим центр и максимальное расстояние

    // В этом блоке необходимо использовать либо раскоменченные две функции: (computeCenter and computeMaxDistance), либо закоменченные две функции: (computeOrtoCenter and computeleights), не перемешивая их между собой.
    Point3D center = computeCenter(points);
    double maxDist = computeMaxDistance(points, center);
    //Point3D center = computeOrtoCenter(points);
    //double maxDist = computeleights(points);

    // 2. Подготавливаем размеры ячеек
    vector<double> epsilons;
    for (int i = 0; i < numScales; ++i) { double epsilon = maxDist / pow(2, i); epsilons.push_back(epsilon); }

    // 3. Для каждого epsilon считаем число занятых ячеек
    vector<int> total_count;

    for (double epsilon : epsilons) {
        if (epsilon <= 0.0) continue;
        using Voxel = tuple<int, int, int>;
        set<Voxel> Voxels;

        for (const auto& point : points) {
            int Lx = (point.x - (center.x - maxDist)) / epsilon;
            int Ly = (point.y - (center.y - maxDist)) / epsilon;
            int Lz = (point.z - (center.z - maxDist)) / epsilon;
            Voxels.insert({ Lx, Ly, Lz });
        }
        total_count.push_back((int)Voxels.size());
    }


    // 4. Линейная регрессия для log(N) vs log(1/epsilon)
    double sumLogN = 0.0, sumLogInvEps = 0.0, sumLogNLogInvEps = 0.0, sumLogInvEpsSq = 0.0;
    for (int i = 0; i < numScales; ++i) {

        double logN = log(total_count[i]);
        double logInvEps = log(1.0 / epsilons[i]);

        sumLogN += logN;
        sumLogInvEps += logInvEps;
        sumLogNLogInvEps += logN * logInvEps;
        sumLogInvEpsSq += logInvEps * logInvEps;
    }

    double D = (numScales * sumLogNLogInvEps - sumLogN * sumLogInvEps) / (numScales * sumLogInvEpsSq - sumLogInvEps * sumLogInvEps);
    return D;
}


vector<double> globalFunction(const vector<Point3D>& points, double epsilon) {
    vector<double> fractalDemensions;
    for (const auto& point : points) {
        vector<Point3D> pnts;
        for (const auto& p : points) {
            if (sqrt(pow(fabs(p.x - point.x), 2) + pow(fabs(p.y - point.y), 2) + pow(fabs(p.z - point.z), 2)) <= epsilon) {pnts.push_back(p);}
        }
        
        double fractalDemension = computeFractalDimension2(pnts);
        cout << "fractalDemension - " << fractalDemension << '\n';
        fractalDemensions.push_back(fractalDemension);
    }
    return fractalDemensions;
}

    
