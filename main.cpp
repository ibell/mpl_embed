#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/eigen.h>
namespace py = pybind11;

#include <Eigen/Dense>

int main(){
    Py_Initialize();
    
    // Import numpy and matplotlib
    py::object np = py::module::import("numpy");
    py::module plt = py::module::import("matplotlib.pyplot");

    // Create a linearly-spaced vector in numpy
    auto x1 = np.attr("linspace")(0,10,300).attr("tolist")(); // Vector converted to list, though not necessary
    auto y1 = np.attr("sin")(x1);
    plt.attr("plot")(x1, y1, "o-");
    
    // Do the same exercise with Eigen VectorXd, except cos(x) instead of sin(x)
    Eigen::VectorXd x2 = Eigen::VectorXd::LinSpaced(300, 0, 10);
    // The Eigen::Ref passes a reference to an Eigen MatrixXd, which should avoid the copy
    // but a temporary numpy array is created
    auto y2 = np.attr("cos")(Eigen::Ref<Eigen::VectorXd>(x2));
    plt.attr("plot")(x2, y2, "^-");
    
    plt.attr("show")();

    return 0;
}