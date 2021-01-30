import { getRepository } from 'typeorm'
import { Review } from './../database/entity/Review'
import { User } from '../database/entity/User'
import { Business } from '../database/entity/Business'

//* Helper methods for development
async function getAllReviews(req, res) {
    res.status(200).json(
        await getRepository(Review)
            .createQueryBuilder('review')
            .leftJoinAndSelect('review.user', 'user')
            .leftJoinAndSelect('review.business', 'business')
            .getMany(),
    )
}

//* Actual Methods for functionality

async function saveReview(req, res) {
    const reviewDataFromClient = req.body
    // get the User object from the database that has the same id as passed from the client
    let user = await getRepository(User)
        .createQueryBuilder('user')
        .where('user.id = :id', { id: reviewDataFromClient.userId })
        .getOne()

    // get the business object from the database that the review is being left on
    let business = await getRepository(Business)
        .createQueryBuilder('business')
        .where('business.id = :id', { id: reviewDataFromClient.businessId })
        .getOne()

    // create a new Reviews object and save it to the database
    let review = new Review()
    review.rating = reviewDataFromClient.rating
    review.comment = reviewDataFromClient.comment
    review.user = user
    review.business = business
    await getRepository(Review).save(review)

    // update the average rating for a business
    let reviewsOnBusiness = await getRepository(Review)
        .createQueryBuilder('review')
        .leftJoinAndSelect('review.user', 'user')
        .where('review.business.id = :businessId', {
            businessId: reviewDataFromClient.businessId,
        })
        .getMany()

    business.averageRating = getAverageRating(reviewsOnBusiness)

    await getRepository(Business).save(business)

    res.status(201).send(
        `Success! Saved ${user.firstName}'s review of ${business.name} to the database.`,
    )
}

function getAverageRating(reviewsOnBusiness) {
    let sum = 0
    reviewsOnBusiness.forEach((review) => {
        sum += review.rating
    })

    return sum / reviewsOnBusiness.length
}

export default {
    saveReview,
    getAllReviews,
}
