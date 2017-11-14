#pragma once
#include <array>
#include <cassert>

template<unsigned int width, unsigned int height = width>
class Matrix
{
private:
	template<bool constant> friend class cell_proxy;
	//TODO: Figure out if I want this class to be like uncopyable and stuff
	template<bool constant> class cell_proxy
	{
		using MatrixType = std::conditional_t<constant, const Matrix<width, height>&, Matrix<width, height>&>;

		MatrixType matrix;
		unsigned int x;
	public:
		cell_proxy(MatrixType matrix, unsigned int x) : matrix(matrix), x(x) {}

		auto operator[](unsigned int index_y) -> std::conditional_t<constant, const float&, float&>
		{
			return matrix.cells.at(x*height + index_y);
		}
	};

public:
	static constexpr unsigned int Rows = width;
	//an alias for Rows
	static constexpr unsigned int Width = width;
	static constexpr unsigned int Columns = height;
	//an alias for Columns
	static constexpr unsigned int Height = height;

	//Default constructor which initialises every cell to 0
	Matrix()
	{
	}

	Matrix(std::initializer_list<std::initializer_list<float>> init_list)
	{
		auto list_height = init_list.size();
		auto it = init_list.begin();
		
		auto list_width = (*it).size();
#if defined(_DEBUG) && !defined(MATH_DISABLE_WARNINGS)
		//TODO: Make this a runtime assert, maybe. test it.
		assert(list_height == Height || list_width == Width, "the initializer list height or width does not match up with the matrix width or height");

		//check each horizontal line to see if they are the same size
		auto check_it = init_list.begin();
		for( ++check_it /*increment because we already saved the first item*/ ; check_it != init_list.end(); ++check_it)
		{
			auto horizontal_list = *check_it;
			assert(list_width == horizontal_list.size(), "The initializer list width is not a consistent number");
		}
#endif
		int vertical = 0;
		for(; it != init_list.end(); ++it)
		{
			int horizontal = 0;
			for(auto it_horizontal = it->begin(); it_horizontal != it->end(); ++it_horizontal)
			{
				float f = *it_horizontal;

				cells[vertical * height + horizontal] = f;

				horizontal++;
			}
			vertical++;
		}
	}

	float& operator()(unsigned int index_x, unsigned int index_y)
	{
		return cells[index_x * height + index_y];
	}
	
	const float& operator()(unsigned int index_x, unsigned int index_y) const
	{
		return cells[index_x * height + index_y];
	}

	cell_proxy<false> operator[](unsigned int index_x)
	{
		return { *this, index_x };
	}

	cell_proxy<true> operator[](unsigned int index_x) const
	{
		return { *this, index_x };
	}

	Matrix<Width, Height> operator+(const Matrix<Width, Height>& b)
	{
		auto& a = *this;
		Matrix<Width, Height> matrix;

		for(int x = 0; x < Width; x++)
		{
			for(int y = 0; y < Height; y++)
			{
				matrix[x][y] = a[x][y] + b[x][y];
			}
		}

		return matrix;
	}

	Matrix<Width, Height> operator-(const Matrix<Width, Height>& b)
	{
		auto& a = *this;
		Matrix<Width, Height> matrix;

		for (int x = 0; x < Width; x++)
		{
			for (int y = 0; y < Height; y++)
			{
				matrix[x][y] = a[x][y] - b[x][y];
			}
		}

		return matrix;
	}

	template<unsigned other_width, unsigned other_height, 
		typename = std::enable_if_t<width == other_height>>
		Matrix<std::min(other_width, width)> operator*(const Matrix<other_width, other_height>& b)
	{
		constexpr unsigned w = std::min(other_width, width);

		Matrix<w, other_height> matrix;
		for(int x = 0; x < w; x++)
		{
			for(int y = 0; y < other_height; y++)
			{
				matrix[x][y] = 
			}
		}

		return {};
	}

	static const Matrix identity;

private:
	static constexpr auto total_cells = width * height;

	std::array<float, total_cells> cells = {};

	
};

template<unsigned int width, unsigned int height>
constexpr Matrix<width, height> make_identity_matrix()
{
	if (width != height)
		return Matrix<width, height>();

	Matrix<width, height> matrix;
	for (int y = 0; y < height; y++)
	{
		matrix[y][y] = 1.f;
	}
	return matrix;
}

template<unsigned int width, unsigned int height>
const Matrix<width, height> Matrix<width, height>::identity = make_identity_matrix<width, height>();